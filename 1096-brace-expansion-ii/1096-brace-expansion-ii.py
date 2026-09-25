class Solution:
    def multiply(self, A, B):
        ans = set()
        for a in A:
            for b in B:
                ans.add(a + b)
        return ans

    def braceExpansionII(self, expression: str) -> list[str]:
        stack = []
        curr = {""}
        for ch in expression:
            if ch == '{':
                stack.append((curr, set()))
                curr = {""}
            elif ch == ',':
                stack[-1][1].update(curr)
                curr = {""}
            elif ch == '}':
                stack[-1][1].update(curr)
                prev, group = stack.pop()
                curr = self.multiply(prev, group)
            else:
                curr = self.multiply(curr, {ch})
        return sorted(curr)