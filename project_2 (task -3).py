import random
import string

class SmartPassword:
    def __init__(self, length):
        self.length = length
        self.password = ""

    def generate(self):
        chars = string.ascii_letters + string.digits + "!@#$%^&*"
        self.password = "".join(random.choice(chars) for _ in range(self.length))

    def strength_score(self):
        score = 0
        for ch in self.password:
            if ch.isupper():
                score += 2
            elif ch.islower():
                score += 1
            elif ch.isdigit():
                score += 3
            else:
                score += 4
        return score

    def strength_level(self):
        score = self.strength_score()
        if score < 20:
            return "WEAK ❌"
        elif score < 35:
            return "MEDIUM ⚠️"
        else:
            return "STRONG 🔥"

    def display(self):
        print("\n🔐 Password Generated Successfully!")
        print("👉 Password        :", self.password)
        print("📊 Strength Score  :", self.strength_score())
        print("💪 Strength Level :", self.strength_level())


# -------- Main Program --------
print("✨ Welcome to Smart Password Generator ✨")

length = int(input("📥 Enter password length: "))

sp = SmartPassword(length)
sp.generate()
sp.display()
