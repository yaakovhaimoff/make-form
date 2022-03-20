#include <memory>
#include <string>
#include <iostream>
#include <cstdlib> // for system()
#include <cstdint> // for uint32_t
#include <chrono>  // for currentYear() implementation

//------------------- User includes ----------------------------

// A class that represents a form. A form has many fields
#include "Form.h"

// A class that represents a field. A field can have one or more validator
#include "Field.h"

// A class that represents a range validator.
// It validates if a field value is in some range.
// The type used as template parameter must implement < and > operators.
#include "RangeValidator.h"

// A class that represents a minimal value validator.
// It validates if a field value is not less than some minimal value.
// The type used as template parameter must implement > operator and support to_string() function.
#include "MinValidator.h"

// A class that represents a no-digit-characters validator.
// It validates that the field value contains no digits.
// Works only on std::string.
#include "NoDigitValidator.h"

// A class that represents an ID validator.
// ID validation is done using the control digit.
// Works only on the type 'uint32_t'.
#include "IdValidator.h"

// A class that represents the value use for faculty field.
// The class must override the << and >> operators.
// >> operator reads an int and << operator prints faculty name if the value is
// valid and if not - the number.
#include "FacultyValue.h"

// A class that represents a faculty-vs.-year validator.
// It checks if the faculty and year supplied matches each other.
// The types used as template parameter must be Field.
#include "Faculty2YearValidator.h"

// A class that represents a courses-vs.-year validator.
// It checks if the course count and year supplied matches each other.
// The types used as template parameter must be Field.
#include "Courses2YearValidator.h"

//------------------- Function declarations ----------------------------

// Prints welcome message to the given std::ostream
void displayWelcomeMessage();

// Prints goodbye message to the given std::ostream
void displayGoodbyeMessage();

// Prints error message to the given std::ostream
void displayErrorMessage();

// Prints form to the given std::ostream
void displayFormFields(const Form& form);

// Utility function for clearing the terminal screen
void clearScreen();

// Utility function for getting current year from computer clock
int currentYear();

//------------------- consts --------------------------

const int MAX_POSSIBLE_YEAR = 7;
const int MIN_AGE = 16;
const int MAX_AGE = 100;
const int N_TIMES = 60;
const std::string MESSAGE_LINE = '+' + std::string(N_TIMES, '-') + '+' + '\n';

//------------------- main ----------------------------

int main()
{
    // Creating the form fields
    auto nameField        = std::make_unique<Field<std::string>> ("What is your name?");
    // equivalent to:
    // std::unique_ptr<Field<std::string>> nameField(new Field<std::string>("What is your name?"));
    auto idField          = std::make_unique<Field<uint32_t>>    ("What is your ID?");
    auto yearOfBirthField = std::make_unique<Field<int>>         ("What is your year of birth?");
    auto facultyField     = std::make_unique<Field<FacultyValue>>("What faculty are you registering to?\n"
                                                                  "(1-Computer Science, 2-Medicine, 3-Literature)");
    auto yearField        = std::make_unique<Field<int>>         ("Which year is it in your studies? (1-"
                                                                  + std::to_string(MAX_POSSIBLE_YEAR) + ")");
    auto courseField      = std::make_unique<Field<short>>       ("How many courses you are taking this year?");

    // Creating the field validators
    auto nameValidator    = std::make_unique<NoDigitValidator>            ();
    auto idValidator      = std::make_unique<IDValidator>                 ();
    auto ageValidator     = std::make_unique<RangeValidator<int>>         (currentYear()-MAX_AGE, currentYear()-MIN_AGE);
    auto facultyValidator = std::make_unique<RangeValidator<FacultyValue>>(1, 3);
    auto yearValidator    = std::make_unique<RangeValidator<int>>         (1, MAX_POSSIBLE_YEAR);
    auto courseValidator  = std::make_unique<MinValidator<short>>         (2);

    // Adding the validators to the fields
    nameField       ->addValidator(nameValidator.get());
    idField         ->addValidator(idValidator.get());
    yearOfBirthField->addValidator(ageValidator.get());
    facultyField    ->addValidator(facultyValidator.get());
    yearField       ->addValidator(yearValidator.get());
    courseField     ->addValidator(courseValidator.get());

    // Creating form validators
    auto facultyToYearValidator
        = std::make_unique<Faculty2YearValidator<Field<FacultyValue>, Field<int>>>(facultyField.get(), yearField.get());
    auto coursesToYearValidator
        = std::make_unique<Courses2YearValidator<Field<short>, Field<int>>>(courseField.get(), yearField.get());

    // Creating the form and adding the fields to it
    Form myForm;
    myForm.addField(nameField.get());
    myForm.addField(idField.get());
    myForm.addField(yearOfBirthField.get());
    myForm.addField(facultyField.get());
    myForm.addField(yearField.get());
    myForm.addField(courseField.get());

    // Adding form validators
    myForm.addValidator(facultyToYearValidator.get());
    myForm.addValidator(coursesToYearValidator.get());

    // Getting the information from the user
    clearScreen();
    displayWelcomeMessage();

    // Get the input only for empty or not valid fields
    myForm.fillForm();

    // Validation loop
    for (auto formIsCorrect = myForm.validateForm(); !formIsCorrect; formIsCorrect = myForm.validateForm())
    {
        // Displays all form fields with value (and error if not valid)
        clearScreen();
        displayErrorMessage();

        displayFormFields(myForm);

        myForm.fillForm();
    }

    clearScreen();
    displayGoodbyeMessage();
    displayFormFields(myForm);
}

void displayFormFields(const Form& form)
{
    std::cout << form << '\n';
}

void displayWelcomeMessage()
{
    std::cout << MESSAGE_LINE;
    std::cout << std::format("|{:^60}|\n|{:^60}|\n",
        "Hello and welcome!", "In order to register please fill in the fields below");
    std::cout << MESSAGE_LINE;
}

void displayErrorMessage()
{
    std::cout << MESSAGE_LINE;
    std::cout << std::format("|{:^60}|\n|{:^60}|\n",
        "There was an error in at least one of the fields!", "Please correct the error(s)");
    std::cout << MESSAGE_LINE;
}

void displayGoodbyeMessage()
{
    std::cout << MESSAGE_LINE;
    std::cout << std::format("|{:^60}|\n|{:^60}|\n",
        "Thank you!", "This is the data you sent:");
    std::cout << MESSAGE_LINE;
}

void clearScreen()
{
#ifdef WIN32
    system("cls");
#else
    system("clear");
#endif
}


int currentYear()
{
    namespace C = std::chrono;
    auto ymd = C::year_month_day(C::floor<C::days>(C::system_clock::now()));
    return static_cast<int>(ymd.year());
}
