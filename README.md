# 🔐Password Hashing Demo (Learning)

***⚠️Warning: For educational purposes only. Don't deploy in production environments.***

## ⚠️Security Notice
- Uses `std::hash` which is **NOT** secure against cryptography
- Without proper key stretching (use bcrypt/Argon2 instead)
- Not GPU-resistant
- Demo salt generation is acceptable compared to most DIY attempts but still not production-ready


## Why This Exists
This project is meant to help beginners to understand the basic concepts behind password hashing
This demo demonstrates simple security concepts but highlights why you should:
- Never roll your own crypto
- Use well-tested libraries
- Follow OWASP guidelines

## How It Works
- Accepts a password and number of salt rounds as input
- Generates a 16-byte random hex salt
- Hashes the password + salt using `std::hash` for `n` rounds
- Outputs the salt and final hash (in hex)
