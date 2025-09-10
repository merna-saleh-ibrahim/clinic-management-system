# 🏥 Clinic Management System (C Language)

A console-based clinic management system written in C that supports:

---

## 👩‍⚕️ Admin Mode Features

- 🔐 Password protected (default: `1234`) with 3 attempts.
- ➕ Add new patient records (name, age, gender, unique ID).
- ✏️ Edit existing patient data by ID.
- 📅 Reserve time slots with the doctor.
- ❌ Cancel reservations.

---

## 👤 User Mode Features

- 📄 View patient record by ID.
- 🗓️ View today's reservations with their status (available/reserved).

---

## 🛠️ How to Compile

Use `gcc` to compile:

```bash
gcc main.c -o clinic
./clinic
