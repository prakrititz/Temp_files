class Solution:
    def isPalindrome(self, s: str) -> bool:
        x = ""

        for c in s:
            if c.isalnum():
                x += c.lower()

        return x == x[::-1]