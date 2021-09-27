# bank-credit-card-validator-management-system


The project provides the functioning of a bank's system to validate a credit card and manage accounts.
It uses LUHN'S ALGORITHM to validate a credit card.The Luhn Algorithm—also known as the “Modulus 10 Algorithm”—is a formula that is used to determine whether the identification number provided by a user is accurate. The formula is widely used in validating credit card numbers, as well as other number sequences such as government Social Security Numbers (SSNs).
Now-a-days, the Luhn Algorithm is an essential component in the electronics payments system and is used by all major credit cards.

KEY TAKEAWAYS
1.The Luhn Algorithm is a mathematical formula developed in the late 1950s.
2.It is widely used to validate the authenticity of identification numbers.
3.In finance, it has helped increase electronic payments processing by rapidly identifying mis-entered credit card numbers.

LUHN'S ALGORITHM-->
This will be explained with example of a Visa number: 4003600000000014

1. Multiply the digits from the back, starting from the second-to-last. Skip one number, double the next until you’re now on the first number. 
    4003600000000014
    1 x 2 + 0 x 2 + 0 x 2 + 0 x 2 + 0 x 2 + 6 x 2 + 0 x 2 + 4 x 2
    
2. Now, we have product digits for all doubled digits, e.g. the product digit of 1 × 2 is 2. However,  the product digit of 6 × 2 will be 1 + 2 (derived from its product '12') because 12 is higher than 10. Add all the derived product digits together. 
    = 2 + 0 + 0 + 0 + 0 + 1 + 2 + 0 + 8 = 13

3. The sum derived should be added to the sum of the digits that weren’t doubled. 
    13 + 4 + 0 + 0 + 0 + 0 + 0 + 3 + 0 = 20

4. If the last digit in the total is 0, then the set of numbers is valid.

The last digit in 20 is 0. So, the Visa number is correct.

REAL LIFE APPLICATIONS
An error report usually comes up where wrong account information is inputted into an electronic payment system. This is because the resulting number generated by the algorithm after a set of numbers is entered doesn’t match the expected resulting number assigned by the Luhn Algorithm to that set of numbers. That expected resulting number is called a check digit, and it offers the most significant real life application of the Luhn Algorithm.

Check digits help to verify whether a set of numbers is accurate. An interesting fact about check digits is that the Luhn Algorithm determines them, not the credit card company. The algorithm does this based on the numbers preceding the check digit, which is usually printed as the last credit card digit.

Not only that, the Luhn Algorithm is also incorporated into code libraries and programming languages, thereby making it possible to integrate identification numbers in software applications.


LIMITATIONS
One major limitation is that the Luhn Algorithm can only detect single digit errors, including transpositions of adjacent numbers. However, this isn’t the case for transpositions of the following sequence: “(first-valid-character)(last-valid-character)” to “(last-valid-character)(first-valid-character)” or vice versa.
What this means is, in the case of a 0 – 9 digit set, transpositions of the ‘09’ to ‘90’ or vice versa won’t be detected by the Luhn Algorithm.
Be that as it may, the algorithm enjoys wide acceptance particularly in finance, as it speeds up electronic payment processes and also makes them relatively easy.



The project implements the LUHN'S ALGORITHM in C++ and offers an effective bank management and credit card validation system.
