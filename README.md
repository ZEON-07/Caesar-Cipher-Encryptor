# CLI Caesar Cipher Encryptor

A starter C boilerplate for a Command-Line Interface (CLI) Caesar Cipher project. This repository provides the foundation for reading plaintext and an integer shift key from standard input, with challenges outlined below for participants to solve.

---

## Project Structure

```text
.
├── main.c       # Main entry point and CLI input/output handling
└── README.md    # Project overview and workshop instructions
```

---

## Compilation and Execution

### Compiling with `gcc`

Compile `main.c` using standard flags:

```bash
gcc -Wall -Wextra -std=c11 main.c -o caesar
```

*(On Windows PowerShell or Command Prompt, this generates `caesar.exe`)*

### Running the Program

Run the compiled executable:

**Linux / macOS:**
```bash
./caesar
```

**Windows:**
```powershell
.\caesar.exe
```

---

## Issues / Tasks to Solve

Work through the following challenges sequentially:

### Issue 1: ASCII Math in `encrypt()`
Inside the [`encrypt()`](file:///c:/Code%20Arena/Caesar%20Cipher%20Encryptor/main.c#L12) function in [main.c](file:///c:/Code%20Arena/Caesar%20Cipher%20Encryptor/main.c):
- Iterate through each character of the string until the null terminator (`\0`).
- Apply ASCII arithmetic to shift alphabetical characters by `shift` positions.
- Preserve case: ensure uppercase characters remain uppercase and lowercase remain lowercase. Non-alphabetic characters (e.g., spaces, punctuation, digits) should remain unchanged.

### Issue 2: Alphabet Wrap-Around
Handle boundary overflow and wrap-around:
- Shifting past `'Z'` or `'z'` must cycle back to `'A'` or `'a'` (e.g., `'Z'` shifted by 1 becomes `'A'`; `'y'` shifted by 3 becomes `'b'`).
- Ensure negative shifts or shift keys larger than 26 wrap around smoothly using modulo arithmetic: `(char - base + shift) % 26 + base`.
- Be mindful of negative modulo results in C.

### Issue 3: Implement `decrypt()`
- Create a `decrypt(char *text, int shift)` function that reverses the encryption transformation.
- Extend the CLI prompt or provide an option allowing the user to select between encryption and decryption.

### Issue 4: Header Extraction and Git File Tracking
- Extract the cipher function declarations and definitions into separate modular files:
  - Create `cipher.h` (function prototypes and documentation).
  - Create `cipher.c` (implementations of `encrypt()` and `decrypt()`).
  - Update `main.c` to `#include "cipher.h"`.
- Update your compilation command to link multiple source files:
  ```bash
  gcc -Wall -Wextra -std=c11 main.c cipher.c -o caesar
  ```
- Practice Git file tracking:
  - Check repository status: `git status`
  - Stage the new header and source files: `git add cipher.h cipher.c main.c`
  - Commit your changes with an informative message: `git commit -m "Refactor cipher logic into cipher.h and cipher.c"`

---

## Example Expected Behavior (Post-Solution)

```text
Enter plaintext: Hello, World!
Enter shift key (integer): 3
Ciphertext: Khoor, Zruog!
```
