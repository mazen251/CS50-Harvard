# Week 0: Scratch

## Numbers and Letters Representation

- **Numbers** are represented as numeric values.

- **Letters** are represented by assigning a number to each letter. For instance, the capital letter 'A' is represented by the number 65 in decimal, which corresponds to `01000001` in binary (1 byte = 8 bits). A byte can represent a maximum value of 255 (from 0 to 255), with `255 = 128 + 64 + 32 + 16 + 8 + 4 + 2 + 1`.

### ASCII and Unicode

- **ASCII**: The American Standard Code for Information Interchange, originally used to represent English characters. ASCII uses 7 or 8 bits per character, which is sufficient for English but not for other languages with larger alphabets.

- **Unicode**: A more comprehensive standard that evolved to address the limitations of ASCII. Unicode can use 16, 24, or even 32 bits per character, allowing it to represent a vast number of characters from various languages and symbols, including emojis.

### Hexadecimal

- Due to the large number of characters that need to be represented in Unicode (sometimes up to 32 bits per character, which is roughly 4 billion possibilities), hexadecimal notation is often used. Hexadecimal uses both numbers (0-9) and letters (A-F) to represent values.

### Emojis

- Emojis are also represented using unique hexadecimal values in the Unicode standard. Variations of emojis, such as different skin tones, are represented by modifying these hexadecimal values. Some complex emojis, like a man and a woman in love with a heart, are composed of multiple Unicode values. 

- **Zero Width Joiners (ZWNJ)**: Special characters in Unicode, represented by `U+200D`, allow for the combination of multiple emojis into a single, more complex emoji.

### Colors

- Colors are represented using the RGB model, where each color (Red, Green, Blue) is represented by a byte (8 bits). The intensity of each color is a value between 0 (faintest) and 255 (brightest). This allows each pixel to be represented by `(0-255, 0-255, 0-255)`.

### Context Matters

- The interpretation of sequences of bits as text, images, or colors depends on the context in which they are used. For example, a sequence of 0's and 1's might represent text in an email but colors in an image-editing program like Photoshop. It is the programmer's responsibility to define the context for interpreting these bits correctly.

## Representation of Music and Video

- **Music**: Could be represented by a combination of numbers for the note, duration, and loudness.

- **Video**: Is essentially a sequence of images, typically displayed at a rate such as 30 frames per second (fps).

## Programming Philosophy

Programming isn't just about writing code or implementing correct algorithms. It’s about creating code that is well-designed and efficient. This is what distinguishes a skilled engineer from others.
