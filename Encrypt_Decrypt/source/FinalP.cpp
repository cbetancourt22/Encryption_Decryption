 
// CHRISTINA MULLAN AND XAVIER BETANCOURT
// WHITWORTH UNIVERSITY
// CS 171-3
// 12-13-2018

//                                                      FINAL PROJECT                                                              //


#include <iostream> // needed to cout
#include <fstream> // Input/ output stream class to operate on files.
#include <cstring> //needed for strings

using namespace std;

   // PASSWORD CHECK //
// PasswordCheck() is a function that takes in a string and compares it to a defined password. I will be needed to acces any function in the programm.
bool passwordCheck(string message) 
{
    string password= "sunflower"; // string defined with the password the gives access to the programm.
        if (message != password) // if the user's input is not equal to the predefined password it returns a false statement. 
        {
            return false;
        } else if (message == password){ // If the user's input is equal to the password, then it returns a true statement.
            return true;
        }
}

   // ENCRYPTION AND DECRYPTION METHODS //
// After calling any of these methods the string will be either encrypted, if it's an encryption method:
// CAESAR ENCRYPTION, AFIN ENCRYPTION, SUBSTITUTION ENCRYPTION, or decrypted, if it's a decryption method.

// 1. CAESAR ENCRYPTION: The Caesar Cipher consists of a three- space displacement in the alphabet,
// for example: a --> d; Z --> C. A phrase or  word will be pased into the function and then
// encrypted using the method. In the Caesar method there are three special cases, which are x,y and z.
// They are special cases because they are the last three letters in the alphabet and they will have to 
// equal to a, b, and c respectively.

void caesarEncrypt (string& s2)
{
    ifstream inFile; // Creation of an object "inFile" in the class fstream. The "i" before fstream meaning input.
    char s1[s2.length()]; // The length of the of the array of characters is the length of the object. 
    strcpy(s1,s2.c_str()); // Take the values of the string and takes each character into one single indice
    char alph[]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"; // All the letters found in the alphabet that will be compared with the letters in the string.

    for (int i=0; i < s2.length(); i++) // Reads from the first character until the the last character based on the length of the array of characters. 
    {
        int j=0; // Initialization of variable j used to go through the letters in the array of characters alph[].

        while (j < 52) // j not greater than 52 because is the limit of the alphabet.
        {
            if ( s1[i] == alph[j] && ( j<23 || (j>=26 && j<49))) // If first letter of string is equal to the first letter in the alphabet, and j < 23 (because of the special case x)
            {                                                    // and also j >= 26 and j < 49 (because of the special case X)
                s1[i] =alph[j+3];   // If the letter in the string complies with the parameters, it is displaced 3 spaces.
                j=52; // j jumps out of the while loop
            }

            if( s1[i] == alph[j] && (j >= 23 && j <26))  // If the letter in the string is found between 23-25, it is a special case x,y or z.
            {
                if (s1[i] == 'x') // x will be replaced for an a.
                {
                    s1[i] = 'a';
                }
                if (s1[i]== 'y') // y will be replaced for a b.
                {
                    s1[i] = 'b';
                }
                if (s1[i] == 'z') // z will be replaced for a c.
                {
                    s1[i] = 'c';
                }
                 j = 52; // j jumps out of the while loop.
            }

            if(s1[i]== alph[j] && (j >= 49 && j <52)) // if the letter in the string is found between 49- 51, the letter is a special character X, Y, or Z.
            {
                if (s1[i] =='X') // X is replaced with an A.
                {
                    s1[i] = 'A';
                }
                if (s1[i] == 'Y') // Y is replaced with a B.
                {
                    s1[i] = 'B';
                }
                if (s1[i] == 'Z') // Z is replaced with a C.
                {
                    s1[i] = 'C';
                }
                 j = 52; // j jumps out of the while loop.
            }
            j++; // j is added one each time.
        }
    }
    s2=s1; // string s2 is now equal to s1, which is the string already encrypted.
}

// 1.1 CAESAR DECRYPTION: The Caesar decryption method is the reverse of the encryption method. Instead of displacing +3 spaces, it now
// displaces -3 spaces, to get a decrypted message. It works about the same, but this time the special characters will be a,b, and c because
// they will need to be equal to x, y, and z respectively since they are the first letter in the alphabet. 
// It passes in a string and decrypts it.

    void caesarDecrypt(string& s2)
    {
        char s1[s2.length()]; 
        strcpy(s1,s2.data()); // Take the values of the string and takes each character into one single indice
        char alph[]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

        for (int i=0; i < s2.length(); i++)
        {
            int j=0;

            while (j < 52) 
            {
                if (s1[i] == alph[j] && ((j>=3 && j < 26) || (j>=29 && j<52))) // In this case j will start at 3 being this d, until 25 which is z. It starts
                {                                                              // again in 29 which is D, until 51 which is Z.
                    s1[i] = alph[j-3];  // If the letter in the string complies with the parameters, it is displaced -3 spaces.
                    j=52; // j jumps out of the while loop.
                }

                if(s1[i]== alph[j] && (j >= 0 && j <3)) // The special characters are found between 0- 2, which are a,b, and c.
                {
                    if (s1[i] =='a') // If the letter in the string is a, it will be replaced by an x.
                    {
                        s1[i] = 'x';
                    }
                    if (s1[i] == 'b') // If the letter in the string is a b, it will be replaced by a y.
                    {
                        s1[i] = 'y';
                    }
                    if (s1[i] == 'c') // If the letter in the string is a c, it will be replaced by a z.
                    {
                        s1[i] = 'z';
                    }
                    j = 52; // j jumps out of the while loop.
                }

                if(s1[i]== alph[j] && ((j >=26 && j< 29))) // The special characters are also found between 26-28, which are A, B, and C.
                {
                    if (s1[i]=='A') // If the letter in the string is A, it will be repaced by an X.
                    {
                        s1[i]= 'X';
                    }
                    if (s1[i]== 'B') // If the letter in the string is a B, it will be replaced by a Y.
                    {
                        s1[i] = 'Y';
                    }
                    if (s1[i] == 'C') // If the letter in the string is a C, it will be replaced by a Z.
                    {
                        s1[i] = 'Z';
                    }
                    j = 52; // j jumps out of the while loop.
                }
                j++; // j is being added 1 at a time.
            }
        }
        s2 = s1; // string s2 is now equal to the encrypted string s1.
    }

// 2. AFIN ENCRYPTION

void afinEncrypt (string& s2)   //Takes in the textfile (string)
{
    char s1[s2.length()];   // Sets the new array that will be worked with to the length of the string that we are encrypting
    strcpy(s1,s2.c_str());  // Take the values of the string and takes each character into one single indice
    int t;                  // Int will be used to implement the numerical aspects of the cipher, once a char is casted into an int. 
    char ch;                // Will be used to examine and change specific letters/characters in the array by interacting with its ASCII value. 

    for (int i=0; i < s2.length()+1; i++)   //loop will be used to iterate through each of the letters in the Char array
    {
        t = s1[i];                          //static casts the indice of the char array into a number by its ASCII value
        if (t >= 65 && t<=90)               //Determines if the letter is an uppercase letter
        {
            t= t-65;                        //Adjusts for scale//needed for putting lowercase and uppercase letters on same scale
            t= (5*t)+8;                     //given its new indice or x value, plug into the linear equation needed for affine Encrypt
            t= t%52;                        //Take the modulus of the value given as needed by the cipher; reorganizes the letters; needs to be 52 because we are using a 52 letter alphabet (treating upper and lower cases separate)
            //Needs to be separation between new letter that will be uppercase and lowercase, reguardless of the fact that these started as only uppercase letters
            if (t >= 0 && t <= 25)          //Evaluates if the new letter should be adjusted as an Uppercase letter
            {
                t= t+65;                    //readjusts for the ASCII value of the new letter
                ch = t;                     //casts the value into a character
                s1[i] = ch;                 //reassigns the indice to the encrypted letter
            }
            else if (t >= 26 && t <= 51)    //Evaluates if the new letter should be treated as a lower case letter
            {
                t= t+71;                    //readjusts for the ASCII value of the new letter
                ch = t;                     //casts the value into a character
                s1[i] = ch;                 //reassigns the indice to the encrypted letter          
            }
        }
        
        else if ( t >= 97 && t <= 122)      //Determines if the starting character was a lower case letter by its ASCII value
        {

            t= t-71;                        //Adjusts for scale //needed for putting lower and upper case letters on the same scale
            t= (5*t)+8;                     //given its new indice or x value, plug into the linear equation needed for affine encrypt
            t= t %52;                       //Take the modulus of the value given as needed by the cipher; reorganizes the letters
        //Needs to be separation between new letters that will be uppercase and lowercase, given the starting character was a lower case. 
            if (t >= 0 && t <= 25)          //Evaluates if the new letter will be an Uppercase letter
            {
                t= t+65;                    //Adjusts to the appropriate ASCII value
                ch = t;                     //Casts the value into a character
                s1[i] = ch;                 //reassigns the indice to the new letter
            }
            else if (t >= 26 && t <= 51)    //Evaluates if the new letter should be treated as a lower case letter.
            {
                t= t+71;                    //Adjusts to the appropriate ASCII value
                ch = t;                     //Casts the value into a character
                s1[i] = ch;                 //reassigns the indice to the new letter
            }
        }
    }
    s2 = s1;                                //sets the encrypted array to be the new string that was originally passed by reference so it can be exported. 
}

// 2.1 AFIN DECRYPTION: The Caesar method will be reversed to get the values without the displacement again.
    void afinDecrypt(string& s2)            //takes in the initial textfile which should be pre encrypted by the Affine Function
    {
        char s1[s2.length()];               // Sets the new array that will be worked with to the length of the string that we are encrypting               
        strcpy(s1,s2.c_str());              // Take the values of the string and takes each character into one single indice
        int t;                              // Int will be used to implement the numerical aspects of the cipher, once a char is casted into an int. 
        char ch;                            // Will be used to examine and change specific letters/characters in the array by interacting with its ASCII value. 

    for (int i=0; i < s2.length()+1; i++)   //loop will be used to iterate through each of the letters in the Char array
    {
        t = s1[i];                          //static casts the indice of the char array into a number by its ASCII value

        if (t >= 65 && t<=90)               //Determines if the letter is an uppercase letter
        {
            t= t-65;                        //Adjusts for scale//needed for putting lowercase and uppercase letters on same scale

            for (int j =0; j < 3; j++)      //pattern requires that to undo the encyption, the same process needs to be ran 3 times to undo encryption
            {
                t= (5*t)+8;                 //puts the value into the linear equation that was used for the encryption process. 
                t= t%52;                    //uses modulus to rotate or reorganize the letters. 
            } 
            if (t >= 0 && t <= 25)          //Evaluates if the new value shows a Uppercase letter
            {
                t= t+65;                    //Adjusts to the appropriate ASCII value given that the letter is supposed to be uppercase
                ch = t;                     //casts value to the character
                s1[i] = ch;                 //reassigns the array indice to the decrypted letter
            }
            else if (t >= 26 && t <= 51)    //Evaluates if the new value shows a lowercase letter
            {
                t= t+71;                    //Adjusts to the appropriate ASCII value given that the letter is supposed to be lowercase
                ch = t;                     //casts value to the character
                s1[i] = ch;                 //reassigns the array indic to the decrypted letter   
            }

        } 
        else if ( t >= 97 && t <= 122)      //Determines if the Encrypted letter is a lower case letter
        {
            t= t-71;                        //Adjusts for scale//needed for putting lowercase and uppercase letters on the same scale

            for (int j =0; j < 3; j++)      //pattern requires that to undo the encyption, the same process needs to be ran 3 times to undo encryption
            {
                t= (5*t)+8;                 //puts the value into the linear equation that was used for the encryption process. 
                t= t%52;                    //uses modulus to rotate or reorganize the letters. 
            } 
            if (t >= 0 && t <= 25)          //Evaluates if the new value shows an uppercase letter
            {
                t= t+65;                    //Adjusts to the appropriate ASCII value given that the letter is supposed to be uppercase
                ch = t;                     //casts value to the character
                s1[i] = ch;                 //reassigns the array indice to the decrypted letter
            }
            else if (t >= 26 && t <= 51)    //Evaluates if the new value shows a lowercase letter
            {
                t= t+71;                    //Adjusts to the appropriate ASCII value given that the letter is supposed to be lowercase
                ch = t;                     //casts value to the character
                s1[i] = ch;                 //reassigns the array indic to the decrypted letter   
            }               
        }
    }
    s2 = s1;                                //sets the encrypted array to be the new string that was originally passed by reference so it can be exported. 
}

// 3. SUBSTITUTION ENCRYPTION: The substitution method has a predefined alphabet that doesn't follow the normal 
// order of the alphabet. It assigns an established letter to each of the letters in the normal order alphabet.
// For example the letter A has its established letter that is going to be assigned --> M.

void subsitution (string& s2)
{
    char s1[s2.length()]; // The length of the of the array of characters s1 is the length of the object.
    strcpy(s1,s2.c_str());
    char alph[]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"; // Normal order alphabet defined in an array.
    char sub[]= "MsTfEAktGXzchwjpRLgYOqZVoNlSHivrFmeUBJdubQyaWDxICPhK"; // Mixed alphabet that assigns character to each one of the character in the normal order alphabet.

    for(int i =0; i< s2.length(); i++) // for loop that loops through each one of the letter in the alphabet as long as it is less than the length of the object.
    {
        int j =0; // Variable j that loops through each one of the letter in the mixed alphabet.

        while(j<52) // It runs through the characters from 0 to the last character which is in the position 51.
        {
            if(s1[i]== alph[j]) // It equals the alphabets in the normal order.
            {
                s1[i] = sub[j]; // Substitutes each one of the letters with its predefined character in the mixed alphabet.
                j = 52; // j jumps out of the while loop.
            }
            j++; // j is incremented one character each time.
        }
            
    }
    s2 = s1; // It assigns the string s2 to the new encrypted string s1.
}

// 3.1 SUBSTITUTION DECRYPTION: It reverses the Substitution Encryption assigning the values of the encrypted string to the past values of the string.
void subsitutionDecrypt(string& s2)
{
    char s1[s2.length()];
    strcpy(s1,s2.c_str());
    char alph[]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"; // Normal order alphabet.
    char sub[]= "MsTfEAktGXzchwjpRLgYOqZVoNlSHivrFmeUBJdubQyaWDxICPhK"; // Predefined alphabet for each one of the characters in the normal order alphabet.

    for(int i =0; i < s2.length(); i++)
    {
        int j =0;
        while(j<52)
        {
            if(s1[i] == sub[j]) // Equals both alphabets.
            {
                s1[i] = alph[j]; // Substitues each one of the letters existen in the mixed alphabets with their past values in the normal order alphabet.
                j = 52; // j jumps out of the while loop.
            }
            j++; // j incremented one character each time.
        }
    }  
    s2 = s1; // The new alphabet string is now equal to the past alphabet of normal order.
}

int main()
{
    string _message; // Variable used to get in a response from the user "password".
    string answer; // Variable used to get a second response from the user "Wheter to encrypt or decrypt message".
    string userChoice; // Variable used to get a third response from the user "Which encryption or decryption method would like to use".
    string userChoice2;

    cout << "Enter password: ";
    getline (cin, _message); // gets in the password from the user to be checked by the passwordCheck() function.
    cout << endl;

    if ((passwordCheck(_message)) == true) // If the password is correct it runs the following code.
    {
        cout << "Woudl you like Import and Decrypt an existing file (Enter ID), or Encrypt and Export a new file (Enter EE)? ";
        getline(cin, answer); // gets in the responde to see what the user is going to procede to to.

        if (answer == "EE") // While the answer is Export and Encrypt, it runs the following code.
        {
        
        string textfile2; // string textfile2 that will take in text from the class object inFile.

        cout << endl;
        cout << "Enter a message (please include dashes instead of spaces to write the message): ";
        getline (cin, textfile2); // gets in the message that is going to be encrypted and exported to the text document.

        cout << "Which encryption method would you like to use? Enter A for: Caesar Cipher, Enter B for: Afin Cipher, Enter C for Substitution Cipher: ";
        getline(cin, userChoice); // takes in the user's choice for which one of the methods it will use.
            if (userChoice == "A"||"a") // If the user's choice is A, it runs the following code.
                {
                    caesarEncrypt(textfile2); // It first encrypts the message using Caesar.
                        
                    ofstream outFile; // Creates an object inFile inside the class fstream, the "o" before the fstream meaning output because we are takin out information.
                    outFile.open("textfile.txt"); // Opens the file textfile
                    outFile << textfile2 << endl; // The encrypted message is written into the file
                    outFile.close(); // Function that closes the file because we don't use it again.

            } else if (userChoice == "B"||"b") {
                    afinEncrypt(textfile2); // Encrypts the message using the Afin Method and repeats same procedure.
                        
                    ofstream outFile;
                    outFile.open("textfile.txt");
                    outFile << textfile2 << endl;
                    outFile.close();

            } else if (userChoice == "C"||"c"){
                    subsitution(textfile2); // Encrypts the message using the Substitution Method and repeats same procedure.
                        
                    ofstream outFile;
                    outFile.open("textfile.txt");
                    outFile << textfile2 << endl;
                    outFile.close();
            }

        } else if (answer== "ID") { // While the answer is import and decrypt, it runs the following code.

            ifstream inFile; // Creates an object inFile inside the class fstream, the "i" before the fstream meaning input.
            inFile.open("textfile.txt"); // It creates a text document in the class object.

            // Checks for error: If the file exists or it's corrupted.
            if (inFile.fail()) 
            {
            cerr << "Error opening file" << endl; // cerr catches errors from the user.
            exit (1); // If it does have an error, it exits the program.
            }

            string textfile; // string textfile that will take in text from the class object inFile

            // read a file while inside the object inFile
            while(inFile) 
            {
            cout << endl;
            
            cout << "Which decryption method would you like to use? Enter A for: Caesar Cipher, Enter B for: Afin Cipher, Enter C for Substitution Cipher: ";
            getline(cin, userChoice2); // Takes in the user choice, either A, B, or C.
                if (userChoice2 == "A"||"a") // If choice was A, it runs the following lines of code.
                    {
                        inFile >> textfile; // Access the object inFile and input what is in the line of code and set it equal to textfile.
                        caesarDecrypt(textfile); // It decrypts the message using the Caesar method in the text document from the class.
                        cout << "Message has been decrypted: " << textfile; // outputs the decrypted message.
                        inFile.close(); // Function that closes the file because is not used again.

                } else if (userChoice2 == "B"||"b"){ // If choice is B, it runs the following lines of code.
                        inFile >> textfile; // Access the object inFile and input what is in the line of code and set it equal to textfile.
                        afinDecrypt(textfile); // It decrypts the message using the Afin method in the text document from the class.
                        cout << "Message has been decrypted: " << textfile; // outputs the decrypted message.
                        inFile.close();

                } else if (userChoice2 == "C"||"c"){ // If choice is C, it runs the following lines of code.
                        inFile >> textfile; // Access the object inFile and input what is in the line of code and set it equal to textfile.
                        subsitutionDecrypt(textfile); // It decrypts th message using the substitution method in the text document from the class.
                        cout << "Message has been decrypted: " << textfile; // outputs the decrypted message.
                        inFile.close();
                } else {
                    cout << "Invalid argument" << endl;
                }
                break; // breaks out the while loop.
            }
        }

    }

    if ((passwordCheck(_message)) == false)

    {
        cout << "Invalid Password!";
    }

    return 0;
}

