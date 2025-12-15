import random
import time

# Game configuration
MOVES = {
    "r": "Rock 🪨",
    "p": "Paper 📄",
    "s": "Scissors ✂️"
}

WIN_RULES = {
    "r": "s",
    "s": "p",
    "p": "r"
}

def get_computer_choice():
    return random.choice(list(MOVES.keys()))

def decide_winner(user, computer):
    if user == computer:
        return "tie"
    elif WIN_RULES[user] == computer:
        return "user"
    else:
        return "computer"

def display_round(user, computer, result):
    print("\n🧾 Round Summary")
    print("-" * 25)
    print(f"You chose     : {MOVES[user]}")
    print(f"Computer chose: {MOVES[computer]}")
    
    if result == "user":
        print("🎉 Result: You WIN this round!")
    elif result == "computer":
        print("💻 Result: Computer WINS this round!")
    else:
        print("🤝 Result: It's a TIE!")

def play_game():
    user_score = 0
    computer_score = 0
    round_no = 1

    print("\n🎯 Welcome to Rock–Paper–Scissors")
    print("Type R / P / S to play | Q to quit")

    while True:
        print(f"\n🔄 Round {round_no}")
        user_input = input("Your move (R/P/S): ").lower().strip()

        if user_input == "q":
            break

        if user_input not in MOVES:
            print("❌ Invalid choice! Try again.")
            continue

        computer_choice = get_computer_choice()
        result = decide_winner(user_input, computer_choice)

        if result == "user":
            user_score += 1
        elif result == "computer":
            computer_score += 1

        display_round(user_input, computer_choice, result)

        print(f"\n📊 Scoreboard → You: {user_score} | Computer: {computer_score}")
        round_no += 1
        time.sleep(1)

    print("\n🏁 Game Over")
    print(f"Final Score → You: {user_score} | Computer: {computer_score}")
    
    if user_score > computer_score:
        print("🏆 Overall Winner: YOU!")
    elif computer_score > user_score:
        print("💻 Overall Winner: COMPUTER!")
    else:
        print("🤝 Overall Result: DRAW!")

# Run the game
play_game()
