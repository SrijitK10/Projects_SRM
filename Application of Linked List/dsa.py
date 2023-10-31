import tkinter as tk
from PIL import Image, ImageTk  # For displaying images

class DirectionNode:
    def __init__(self, instruction):
        self.instruction = instruction
        self.next = None

class DirectionsLinkedList:
    def __init__(self):
        self.head = None
        self.current = None

    def add_direction(self, instruction):
        new_node = DirectionNode(instruction)
        if not self.head:
            self.head = new_node
            self.current = new_node
        else:
            self.current.next = new_node
            self.current = new_node

    def get_current_instruction(self):
        if self.current:
            return self.current.instruction
        return ""

    def move_to_next(self):
        if self.current and self.current.next:
            self.current = self.current.next

    def move_to_previous(self):
        if not self.head or self.current == self.head:
            return
        temp = self.head
        while temp.next != self.current:
            temp = temp.next
        self.current = temp

# Initialize the linked list with directions
directions_list = DirectionsLinkedList()
directions = [
    "Start at SRM University Kattankulathur",
    "Head west on Potheri SRM Nagar Road towards NH179B.",
    "Turn left onto NH179B.",
    "Continue on NH179B/NH32, passing by SRM University Kattankulathur on your left.",
    "Keep left at the fork and follow signs for NH32/Chennai.",
    "Use the right 2 lanes to take the exit towards Velachery Road.",
    "Turn left onto Velachery Road.",
    "Keep left at the ork and follow signs for Velachery Road/Chennai.",
    "Turn left onto Velachery Main Road.",
    "Phoenix MarketCity Chennai will be on your right."
    ]


for direction in directions:
    directions_list.add_direction(direction)

# Create the main window
root = tk.Tk()
root.title("Driving Directions")

heading_label = tk.Label(root, text="IMPLEMENTATION OF LINKED LIST IN GOOGLE MAPS\n"
                                    "by SRIJIT KUNDU(RA2211003010881), DIPTAYAN JASH(RA2211003010890), RUDRAJIT DUTTA (RA2211003010913)",
                         font=("Arial", 12), justify="center")
heading_label.pack()

# Load and display an image
image = Image.open("./Maps.png")  # Replace "your_image.png" with your image file
# resize_image = image.resize((400, 300))
photo = ImageTk.PhotoImage(image)
image_label = tk.Label(root, image=photo)
image_label.pack(pady=20)

# Create and configure labels
direction_label = tk.Label(root, text="", wraplength=300)
direction_label.pack(pady=20)

def update_direction_label():
    direction_label.config(text=directions_list.get_current_instruction())

update_direction_label()

# Create "NEXT" and "PREVIOUS" buttons
next_button = tk.Button(root, text="NEXT", command=lambda: [directions_list.move_to_next(), update_direction_label()])
previous_button = tk.Button(root, text="PREVIOUS", command=lambda: [directions_list.move_to_previous(), update_direction_label()])

previous_button.pack(side="left", padx=10)
next_button.pack(side="right", padx=10)

# Start the GUI main loop
root.mainloop()
