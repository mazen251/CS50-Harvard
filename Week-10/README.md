**Week 10: CyberSecurity**

**Brute Force Attacks**
- Trying all possible possibilities.
  - **Example**:
    - For a 4-digit passcode: 10,000 possibilities (each digit has 10 possibilities: 0-9, thus 10^4).
    - For 4-letter passwords with both upper and lower case alphabets (52 possibilities per letter): ~7 million possibilities (52^4).

**Password Managers**
- Software that stores passwords for you so you don’t have to remember all of them.

**Two-Factor Authentication**
- Uses two methods to authenticate that you are the authorized user.
  - Examples: Phone number, secondary email, USB key, etc.

**Passwords Stored on Servers**
- Typically stored in a hash table where the key is the username or email and the value is the hashed (encrypted) password.

**Salting**
- Mechanism to decrease the likelihood that an attacker will glean information.
  - **Example**: If two users have the same password, salting adds a unique value to each password before hashing to prevent attackers from easily finding matching passwords.

**Cryptography**
- **Symmetric**: Uses the same key for encryption and decryption.
- **Asymmetric**: Uses a pair of keys (Public and Private).

**Pass Keys**
- Newer feature of operating systems that eliminates the need for usernames and passwords.
  - **Process**: When you register on a site, your device generates a public/private key pair. The public key is sent to the website, while the private key remains on your device.

**End-to-End Encryption**
- Ensures that only the communicating users (A and B) can read the messages, and not even the service provider (C) can access the content.

**Secure Deletion**
- Ensures that deleted data is overwritten with zeros or ones to prevent recovery of remnants.
