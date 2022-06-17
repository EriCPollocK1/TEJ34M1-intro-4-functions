/*==============================================================================
 Project: Intro-4-Functions
 Date:    May 16, 2021
 
 This program demonstrates the use of functions, and variable passing between
 the main and function code.
 
 Additional program analysis and programming activities examine function code
 location, function prototypes, and reinforce the concepts of global and local
 variables.
==============================================================================*/

#include    "xc.h"              // Microchip XC8 compiler include file
#include    "stdint.h"          // Include integer definitions
#include    "stdbool.h"         // Include Boolean (true/false) definitions

#include    "UBMP4.h"           // Include UBMP4 constants and functions

// TODO Set linker ROM ranges to 'default,-0-7FF' under "Memory model" pull-down.
// TODO Set linker code offset to '800' under "Additional options" pull-down.

// Button constant definitions
const char noButton = 0;
const char UP = 1;
const char DOWN = 2;
const char left = 3;
const char right = 4;

// Program variable definitions
unsigned char LED5Brightness = 125;
unsigned char button;
unsigned char time;
unsigned char wave;
unsigned char number;
unsigned char H;
unsigned char T;
unsigned char O;

unsigned char button_pressed(void)
{
    if(SW4 == 0)
    {
        return(UP);
    }
    else if(SW5 == 0)
    {
        return(DOWN);
    }
    else if(SW3 == 0)
    {
        return(left);
    }
    else if(SW2 == 0)
    {
        return(right);
    }
    else
    {
        return(noButton);
    }
}

void wave(unsigned char time)
{
    if(time > 0)
    {
        beeper = 1;
        __delay_us(time);
        beeper = 0;
    }
}

void pwm_LED5(unsigned char pwmValue)
{
    for(unsigned char t = 255; t != 0; t --)
    {
        if(pwmValue == t)
        {
            LED5 = 1;
        }
        __delay_us(20);
    }
    // End the pulse if pwmValue < 255
    if(pwmValue < 255)
    {
        LED5 = 0;
    }
}

unsigned char reader (void)
{
    while(number > 100)
    {
        H ++;
        number =- 100;
    }

        while(number > 10)
        {
            T ++;
            number =- 10;
        }

            while(number > 1)
            {
                O ++;
                O --;
            }
}

unsigned char Hundreds(void)
{

    if(H == 1)
    {
        LED3 = 1;
    }
else
{
LED3 = 0;
}

    if(H == 2)
    {
        LED4 = 1;
    }
    else 
    {
        LED4 = 0;
    }

}

unsigned char tens(void)
{
    if(T == 1)
    {
        LED3 = 1;
    }
    else 
    {
        LED3 = 0;
    }

    if(T == 2)
    {
        LED4 = 1;
    }
    else 
    {
        LED4 = 0;
    }

    if(T == 3)
    {
        LED3 = 1;
        LED4 = 1;
    }
    else 
    {
        LED3 = 0;
        LED4 = 0;
    }

    if(T == 4)
    {
        LED5 = 1;
    }
    else 
    {
        LED5 = 0;
    }

    if(T == 5)
    {
        LED3 = 1;
        LED5 = 1;
    }
    else 
    {
        LED3 = 0;
        LED5 = 0;
    }

    if(T == 6)
    {
        LED4 = 1;
        LED5 = 1;
    }
    else 
    {
        LED4 = 0;
        LED5 = 0;
    }

    if(T == 7)
    {
        LED3 = 1;
        LED4 = 1;
        LED5 = 1;
    }
    else 
    {
        LED3 = 0;
        LED4 = 0;
        LED5 = 0;
    }

    if(T == 8)
    {
        LED6 = 1;
    }
    else 
    {
        LED6 = 0;
    }

    if(T == 9)
    {
        LED6 = 1;
        LED3 = 1;  
    }
    else 
    {
        LED3 = 0;
        LED6 = 0;
    }
}


unsigned char ones(void)
{
    if(O == 1)
    {
        LED3 = 1;
    }
    else 
    {
        LED3 = 0;
    }

    if(O == 2)
    {
        LED4 = 1;
    }
    else 
    {
        LED4 = 0;
    }

    if(O == 3)
    {
        LED3 = 1;
        LED4 = 1;
    }
    else 
    {
        LED3 = 0;
        LED4 = 0;
    }

    if(O == 4)
    {
        LED5 = 1;
    }
    else 
    {
        LED5 = 0;
    }

    if(O == 5)
    {
        LED3 = 1;
        LED5 = 1;
    }
    else 
    {
        LED3 = 0;
        LED5 = 0;
    }

    if(O == 6)
    {
        LED3 = 1;
        LED5 = 1;
    }
    else 
    {
        LED3 = 0;
        LED5 = 0;
    }

    if(O == 7)
    {
        LED3 = 1;
        LED4 = 1;
        LED5 = 1;
    }
    else 
    {
      LED3 = 0;
        LED4 = 0;
        LED5 = 0;   
    }
    if(O == 8)
    {
        LED6 = 1;
    }
    else 
    {
        LED6 = 0;
    }

    if(O== 9)
    {
        LED3 = 1;
        LED6 = 1;
    }
    else 
    {
        LED3 = 0;
        LED6 = 0;
    }
}

void pwm_LED5(unsigned char);

int main(void)
{
    OSC_config();               // Configure internal oscillator for 48 MHz
    UBMP4_config();             // Configure on-board UBMP4 I/O devices

 
    while(1)
	{
        // Read up/down buttons and adjust LED5 brightness
        button = button_pressed();
        
        // if(button == UP && LED5Brightness < 255)
        // {
        //     LED5Brightness += 1;
        // }

        // if(button == DOWN && LED5Brightness > 0)
        // {
        //     LED5Brightness -= 1;
        // }
        // if(button == left)
        // {
        //     LED5 = 1;
        //     LED5Brightness = 255;
        // }
        // if(button == right)
        // {
        //     LED5 = 0;
        //     LED5Brightness = 0;
        // }
        // if(button == right)
        // {
        //     LED3 = 1;
        //     LED4 = 0;
        //     LED5 = 0;
        //     LED6 = 0;
        // }
        // if(button == UP)
        // {
        //     LED5 = 1;
        //     LED4 = 0;
        //     LED3 = 0;
        //     LED6 = 0;
        // }
        // if(button == left)
        // {
        //     LED4 = 1;
        //     LED3 = 0;
        //     LED5 = 0;
        //     LED6 = 0;
        // }
        // if(button == DOWN)
        // {
        //     LED6 = 1;
        //     LED3 = 0;
        //     LED4 = 0;
        //     LED5 = 0;
        // }



          


        // PWM LED5 with current brightness
        pwm_LED5(LED5Brightness);
        
        // Activate bootloader if SW1 is pressed.
        if(SW1 == 0)
        {
            RESET();
        }
    }
}

// Move the function code to here in Program Analysis, step 5.


/* Program Analysis
 * 
 * 1.   Which function in this program will run first? How do you know?
 * 
 if button == up will run first as this is the rest position of the button and 
 therefore will run before you press the button.

 * 2.   What is the purpose of the 'unsigned char' variable type declaration in
 *      the button_pressed() function? Is it used by this function to receive
 *      a variable from, or return a variable to the main code?
 * 
 it is used to collect the value of the button and make it easier to right your code later on 

 * 3.   How does the function call statement 'button = button_pressed();' in the
 *      main code support your answer in 2, above?
 * 
 it makes them equal at the start of the real code, this means that I was correct because it then 
 uses the button pressed character to code 
 
 * 4.   What is the purpose of the 'unsigned char' variable type declaration in
 *      the pwm_LED5() function? Where does the value of the variable come from?
 *      Where does this value get stored in the function?
 * 
 this is your full PWM code so that it can all run.the value is stated in the for loop.

 * 5.   C language compilers typically read through the entire program in a
 *      single pass, converting C code into machine code. The two functions,
 *      button_pressed() and pwm_LED5(), are located above the main() function
 *      so that their memory locations and variable requirements will be
 *      determined before the rest of the program compiles. When the compiler
 *      interprets the function call statements in the main code, it already
 *      knows where those functions are to be in memory and which memory locations
 *      are used by their variables.
 * 
 *      Try moving the button_pressed() and pwm_LED5() functions to below the
 *      closing brace of the main() function, and build the code. What happens?
 * 
 it just fails the code and then tells you that you can't put it there.

 *      The compiler should have reported an error since it did not understand
 *      what the function call was referring to because it had not seen the
 *      function before the function call. We can eliminate this error by adding
 *      a function prototype above the main code. The function prototype is like
 *      the function declaration (the first line of the function), and lets the
 *      compiler know both the function's name and the type of variables that
 *      the function will use. A C language 'linker' program will take care of
 *      sorting out the names and memory locations of all of the functions and
 *      variables in a program following the compilation step.
 * 
 *      Let's try this out. Leave the functions in their new location, below
 *      the main() function, and add the two function prototypes (shown below)
 *      above main(), in the location where the functions were originally
 *      located:

unsigned char button_pressed(void);

void pwm_LED5(unsigned char);

 *      What is the difference between the function prototype for pwm_LED5()
 *      and the actual pwm_LED5() function declaration statement later in the
 *      code?
 * 
 the prototype just lets it know that later on there will be a function called this,
 as well it doesn't give the cariable name in the prototype

 * 6.   Building the program with the added function prototypes should now work
 *      without generating errors, just as it did in the original program.
 * 
 *      In C, functions may be located above the code that calls them, below
 *      their function calls if a function prototype is supplied, or even in 
 *      completely separate files known as function libraries.
 * 
 *      Function libraries are typically joined to your project's main '.c' file
 *      using an 'include' statement to a '.h' header file containing both
 *      variable definitions and the function prototypes for an associated C
 *      file which contains the actual function code.
 * 
 *      The '#include "UBMP4.h"' statement near the top of this program is an
 *      example of a statement that adds external functions to our program. The
 *      'UBMP4.h' file contains function prototypes for functions located in
 *      the 'UBMP4.c' file, along with various symbolic constants used by both
 *      our program and the code in the UBMP4.c functions.
 * 
 *      Open the UBMP4.c file to find the OSC_config() and UBMP4_config()
 *      functions called from the main() function in this program. Are any
 *      values passed between this code and the two setup functions? How do
 *      you know?
 * 
 yes it states in the comments that it will clear all the pins, this looks like a set up 
 code to get the chip ready to work, it clears it all and enables buttons and leds as inputs and outputs

 * 7.   The 'button' variable is a global variable because it was assigned
 *      at the beginning of the program, outside of any functions. Global
 *      variables are available to all functions. How does the 'button' variable
 *      get assigned a value? In which function does this occur?
 * 
 it would occur in this file as it is the only file with this variable as well as it, 
 gets put down into the function which is where it is assigned a value

 * 8.   Which variable does the value of LED5Brightness get transferred to in
 *      the pwm_LED5() function? Is this variable global, or local to the LED
 *      function? Could the pwm_LED5 function use the LED5Brightness variable
 *      directly, instead of transferring its value to another variable?
 * 
 it looks like it will be put in as PWMvalue, this will be a local variable to this code,
 yes you could most likely use the variable directly.

 * Programming Activities
 * 
 * 1.   It might be useful to have a button that instantly turns LED D5 fully
 *      on or off instead of waiting for it to brighten and dim while the UP
 *      and DOWN buttons are held to change the PWM duty cycle. But, PWM dimming
 *      dimming capability is still a useful feature that should be retained.
 * 
 *      Modify the button_pressed() and main() functions to use SW3 as an
 *      instant on button, and SW2 as an instant off button. Pressing either of
 *      these buttons will over-write the current LED5Brightness value with
 *      either 255 or 0, while still allowing SW4 and SW5 to adjust the
 *      brightness in smaller increments when pressed.
 *
 * 2.   Create a function that will return a number from 1-4 corresponding to
 *      which of the SW2 to SW5 switches is pressed, or return 0 if no switches
 *      are pressed. Then, create a function that will accept a number from 1 to
 *      4 that lights the corresponding LED beside each button.
 * 
 * 3.   Create a sound function that receives a parameter representing a tone's
 *      period. Modify your button function, above, to return a variable that
 *      will be passed to the sound function to make four different tones.
 * 
 * 4.   A function that converts an 8-bit binary value into its decimal
 *      equivalent would be useful for helping us to debug our programs. Create
 *      a function that converts an 8-bit binary number into three decimal
 *      character variables representing the hundreds, tens and ones digits
 *      of the binary number passed to it. For example, passing the function
 *      a value of 142 will result in the hundreds variable containing the
 *      value 1, the tens variable containing 4, and the ones variable 2. How
 *      could you test this function to verify that it works? Try it!
 */
