
class Solution:
    def removeDigit(self, num: str, dig: str) -> str:
        ans = 0
        for i in range(len(num)):
            if num[i] == dig and int(num[:i] + num[i+1:]) > ans:
                ans = int(num[:i] + num[i+1:])
        return str(ans)

def main():
    s = Solution()
    print(s.removeDigit('1231', '1'))