# Password Strength Regex Tester
## 1. Project Title & Goal
A high-performance, scalable C++ utility designed to verify password complexity against security patterns using a modular, Object-Oriented approach.
## 2. Setup Instructions
To run this project locally, ensure you have a C++ compiler (like g++) installed.
1. Clone the repository or download the main.cpp file.
2. Open your terminal and navigate to the project folder.
3. Compile the code using the following command:g++ main.cpp -o validator
4. Execute the program-

* On Windows: validator or validator.exe
   
* On Mac/Linux: ./validator
### 3. The Logic (How I thought)
Instead of a simple script, I implemented this using a **Modular Class-based** approach.

* **Single-Pass Algorithm:** I optimized the validator to run in **O(n) Time Complexity**, ensuring each character is checked only once.
* **Separation of Concerns:** By returning a `ValidationResult` struct, the code remains **scalable** and **decoupled** from the console output logic.

**Hardest Bug Faced:**
The most difficult challenge was handling **Special Characters** beyond just '@'. I solved this by utilizing the `std::ispunct()` function to ensure full coverage of symbols.

* Time Complexity: $O(N \times L)$
* Space Complexity: $O(L)$
## 4. Output Screenshots
![screenshot_password_checker_1](https://github.com/user-attachments/assets/3c78aa15-c6c3-4a10-9298-686b79b9079e)

## 5. Future Improvements
If given more time, I would implement: 

* Entropy Scoring: To provide a "Strength Meter" (Weak/Medium/Strong). 

* Leaked Password Check: Integration with a database to block commonly compromised passwords.
