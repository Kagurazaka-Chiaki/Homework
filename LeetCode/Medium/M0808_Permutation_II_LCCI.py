class Solution:
    def permutation(self, S: str) -> List[str]:
        if S == "":
            return [""]

        result = set()
        for i in range(0, len(S)):
            for j in self.permutation(S[:i] + S[i + 1:]):
                result.add(S[i] + j)
        return list(result)
