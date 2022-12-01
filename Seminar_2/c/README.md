## Task 1

The problem we need to solve here is to only allow strings to be considered 'valid' if all opening brackets have their respective closing brackets, and that all comments are taken into account. In this case, the multi-line comment, /**/, was especially tricky, since the string will only be considered valid if the brackets prior to an opening statement are enclosed before, and that the actual opening comment is closed with the required */ string.

To solve this problem, I created a node structure that is implemented when creating an abstract stack. Each node points to its successor, creating a virtual stack where memory is allocated dynamically in the heap (ironically enough not in the actual stack memory of the computer).
This data structure is most suitable because it allows us to push symbols onto the stack when they are detected, then when a different arbitrary closing character is detected, we return an error.