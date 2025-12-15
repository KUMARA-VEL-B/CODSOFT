import random
import time

# ================= USER INTERFACE =================
def show_interface():
    print("\n" + "=" * 60)
    print("🎮 WELCOME TO ROCK – PAPER – SCISSORS")
    print("=" * 60)
    print("📌 Instructions:")
    print("  • Enter R or r for Rock 🪨")
    print("  • Enter P or p for Paper 📄")
    print("  • Enter S or s for Scissors ✂️")
    print("  • Enter Q or q to quit the current game")
    print("📌 Rules:")
    print("  • Rock beats Scissors")
    print("  • Scissors beats Paper")
    print("  • Paper beats Rock")
    print("=" * 60)

# ================= GAME DATA =================
MOVES = {
    "r": "Rock 🪨",
    "p": "Paper 📄",
    "s": "Scissors ✂️"
}

BEATS = {
    "r": "s",
    "s": "p",
    "p": "r"
}

# ================= GAME LOGIC =================
def computer_move():
    return random.choice(tuple(MOVES))

def check_result(user, computer):
    if user == computer:
        return "tie"
    if BEATS[user] == computer:
        return "user"
    return "computer"

def display_feedback(user, computer, result):
    print("\n🧾 ROUND FEEDBACK")
    print("-" * 35)
    print(f"Your choice     : {MOVES[user]}")
    print(f"Computer choice : {MOVES[computer]}")

    messages = {
        "user": "🎉 You WIN this round!",
        "computer": "💻 Computer WINS this round!",
        "tie": "🤝 It's a TIE!"
    }
    print(messages[result])

# ================= SINGLE GAME SESSION =================
def play_one_game():
    user_score = 0
    computer_score = 0
    round_no = 1

    show_interface()

    while True:
        print(f"\n🔄 ROUND {round_no}")
        user_input = input("👉 Enter your move (R/P/S or Q): ").strip().lower()

        # Quit current game
        if user_input == "q":
            print("\n🚪 You chose to quit the current game.")
            break

        if user_input not in MOVES:
            print("❌ Invalid input! Please enter R, P, S, or Q.")
            continue

        comp_choice = computer_move()
        result = check_result(user_input, comp_choice)

        if result == "user":
            user_score += 1
        elif result == "computer":
            computer_score += 1

        display_feedback(user_input, comp_choice, result)

        print(f"\n📊 SCOREBOARD → You: {user_score} | Computer: {computer_score}")
        round_no += 1
        time.sleep(1)

    print("\n🏁 GAME ENDED")
    print(f"Final Score → You: {user_score} | Computer: {computer_score}")

# ================= MAIN CONTROLLER =================
while True:
    play_one_game()

    restart = input("\n🔁 Do you want to play the game again? (Yes/No): ").strip().lower()
    if restart != "yes":
        print("\n🙏 Thank you for playing! Goodbye 👋")
        break

