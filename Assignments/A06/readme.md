
# UML Assignment

# Transcript class
- Base class
- composed of a Student object, Grades object, and a Schedule object

# Schedule class
- contains the course number, subject, title, year, semester

# Grades
- contains a key (should be by mustang id), semester, year, crn

# Student
- composed of Classification and GPA
- also has fields for email, first and last name, mustang id, label

# Classification
- Contains a label and an array of two integers for hours
- Only used in Student

# GPA
- Contains GPA in float format
- Also has a void function to return GPA in char form (A, B, C, D, F)
