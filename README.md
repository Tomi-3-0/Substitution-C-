### Background

In a substitution cipher, we “encrypt” (i.e., conceal in a reversible way) a message by replacing every letter with another letter. To do so, we use a key: in this case, a mapping of each of the letters of the alphabet to the letter it should correspond to when we encrypt it. To “decrypt” the message, the receiver of the message would need to know the key, so that they can reverse the process: translating the encrypt text (generally called ciphertext) back into the original message (generally called plaintext).

A key, for example, might be the string NQXPOMAFTRHLZGECYJIUWSKDVB. This 26-character key means that A (the first letter of the alphabet) should be converted into N (the first character of the key), B (the second letter of the alphabet) should be converted into Q (the second character of the key), and so forth.

A message like HELLO, then, would be encrypted as FOLLE, replacing each of the letters according to the mapping determined by the key.

This program called substitution enables you to encrypt messages using a substitution cipher. As the user executes the program, they should decide, by providing a command-line argument, on what the key should be in the secret message provided at runtime.

Here are a few examples of how the program might work. For example, if the user inputs a key of YTNSHKVEFXRBAUQZCLWDMIPGJO and a plaintext of HELLO:
   
    $ ./substitution YTNSHKVEFXRBAUQZCLWDMIPGJO
    plaintext:  HELLO
    ciphertext: EHBBQ

Here’s how the program might work if the user provides a key of VCHPRZGJNTLSKFBDQWAXEUYMOI and a plaintext of hello, world:
    
    $ ./substitution VCHPRZGJNTLSKFBDQWAXEUYMOI
    plaintext:  hello, world
    ciphertext: jrssb, ybwsp

Notice that neither the comma nor the space were substituted by the cipher. Only alphabetical characters were substituted! Notice, too, that the case of the original message has been preserved. Lowercase letters remain lowercase, and uppercase letters remain uppercase.

Whether the characters in the key itself are uppercase or lowercase doesn’t matter. A key of VCHPRZGJNTLSKFBDQWAXEUYMOI is functionally identical to a key of vchprzgjntlskfbdqwaxeuymoi (as is, for that matter, VcHpRzGjNtLsKfBdQwAxEuYmOi).

If a user doesn’t provide a valid key? The program would explain with an error message:

    $ ./substitution ABC
    Key must contain 26 characters.

Or really doesn’t cooperate, providing no command-line argument at all? The program would remind the user how to use the program:

    $ ./substitution
    Usage: ./substitution key

Or doesn’t cooperate, providing too many command-line arguments? The program would also remind the user how to use the program:

    $ ./substitution 1 2 3
    Usage: ./substitution key
