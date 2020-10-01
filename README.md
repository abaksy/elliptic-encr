# Encryption based on Conic Curves

This is a C++ implementation of a basic encryption algorithm that generates an encryption key based on a pseudorandomly parameterized conic curve. 
The inverse function of the same conic curve may then be used to decrypt the encrypted message and return the original message.

The file `encryption.cpp` reads from `data.txt` and writes the encoded text to a text file which is read by the file `decryption.cpp`.


# Encryption Algorithm

The project implements the parabolic encryption algorithm, which takes in a string input, converts each character of the string 
into some another based on the equation of an upward parabola: <code>y<sup>2</sup> = 4ax</code>, where x is the index of that particular input character, 
a is a the encryption distance calculated during runtime and y is the function of x, which is added to the ASCII value of the original 
character to get the encrypted character.

Similarly, the decryption algorithm takes in the encrypted string obtained using the above encryption algorithm, 
applies the inverse function of the parabola function : ```x = -√4ay```  on each character of the string, where y is the index of the 
encrypted input character, a is the same encryption distance as before and x is the function of y, which is added to the ASCII value 
of the encrypted character to get the decrypted character.

# Running Elliptical Encryptor

Compile the encryption file with 

```bash
g++ encryption.cpp -lm
```

Compile the decryption file with
```bash
g++ decryption.cpp -lm
```

Run the encryption with
```bash
./a.out < file_to_encrypt.txt
```

Run the decryption with
```bash
./a.out < file_to_decrypt.txt
```