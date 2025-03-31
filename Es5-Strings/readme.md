## The Power of Flags

**NOTE: FLAGS ARE EXTREMELY POWERFUL.**

Flags in C are variables (usually of type `int` or `bool`) that help track a state. In this case, the `newWord` flag tells us whether the next character should be uppercase or not.

#### How does the `newWord` flag work in  Ex5.c?

📌 **Objective:** We want to detect when a new word starts to capitalize its first letter while keeping the rest lowercase.

- When `newWord = 1` → It means the next alphabetical character will be the beginning of a new word → We make it uppercase.
- When `newWord = 0` → It means we are inside a word → We convert subsequent letters to lowercase.
- When we find a space or a symbol → We set `newWord = 1`, so that when we find the next letter, we know it's a new word.

qua ci metto foto

#### Why is this useful?

- It avoids the need to manually check spaces before each word.
- It simplifies the loop: you only need to iterate through the string once. (Without using flags, you might have to traverse the string separately for each word.)
- It works for any text, regardless of how many spaces there are or whether the letters are already uppercase or lowercase.

#### Conclusion

🚀 Flags are a powerful trick in C (and programming in general) because they allow you to track a state without writing complex code or using deeply nested conditions.


