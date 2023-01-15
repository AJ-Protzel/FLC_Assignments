#include<iostream>
#include<vector>
#include<time.h>
#include<algorithm>
#include<string>
using namespace std; 

//______________________________________________Room
struct Room{ // base struct for each room // base struct for each witness
  int index; // rooms identification number // witness identification number
  string name; // name of room // name of witness
  string title; // title of room // title of witness
  string desc; // description string of room // description string of witness
  string poi; // list of points of interests
  string poi1; // point of interest #1 // question #1 answer
  string poi2; // point of interest #2 // question #2 answer
  string poi3; // point of interest #3 // question #3 answer
};
//______________________________________________Player
class Player{
  private:
    int room; // current room position
    string knotepad; // investogators key notepad
    string notepad; // investigators notepad
    bool r0p1;
    bool r0p2;
    bool r0p3;
    bool r1p1;
    bool r1p2;
    bool r2p1;
    bool r2p2; // key
    bool r4p3;
    bool r6p1;
    bool r6p2; // key
    bool r8p2; // key
    bool r8p3; // key
  public:
    Player(){ // constructor
      room = 0;
      knotepad = "Key Evidence:\n";
      notepad = "\nClues:\n";
      r0p1 = false;
      r0p2 = false;
      r0p3 = false;
      r1p1 = false;
      r1p2 = false;
      r2p1 = false;
      r2p2 = false; // key
      r4p3 = false; // todd green
      r6p1 = false;
      r6p2 = false; // key
      r8p2 = false; // key
      r8p3 = false; // key
    }

    int roomindex(); // return player room number
    bool evidence(int i); // return true if key evidence is found
    void Walk(int i); // move player
    void Investigated(vector<Room> Rooms, int i); // cout poi and add notes
    void KeyNote(string i); // add key note string
    void Note(string i); // add note string
    void Notepad(); // return notes strings
}player;
//-------------------------------------------------------------------------------Player Functions
//_______________________________________________________________roomindex
int Player::roomindex(){
  return room;
}
//_______________________________________________________________evidence
bool Player::evidence(int i){
  if(i == 0){
    if(r2p2 == true || r6p2 == true || r8p2 == true || r8p3 == true){
      return true;
    }
  }
  else if(i == 1){
    if(r4p3 == true){
      return true;
    }
  }
  else if(i == 2){
    int ii = 0;

    if(r2p2 == true){
      ii++;
    }
    if(r6p2 == true){
      ii++;
    }
    if(r8p2 == true){
      ii++;
    }
    if(r8p3 == true){
      ii++;
    }

    if(ii == 4){
      return true;
    }
  }
  return false;
}
//_______________________________________________________________Walk
void Player::Walk(int i){
  room = i;
}
//_______________________________________________________________Investigated
void Player::Investigated(vector<Room> Rooms, int i){
  cout << endl;
  switch (i){ // poi
    case 0: cout << Rooms[room].poi1; break;
    case 1: cout << Rooms[room].poi2; break;
    case 2: cout << Rooms[room].poi3; break;
  }

  if(room == 0){
    if(i == 0 && r0p1 == false){
      cout << endl << endl << "~~Note added~~";
      Note("Victim stabbed in right side of neck");
      r0p1 = true;
    }
    else if(i == 1 && r0p2 == false){
      cout << endl << endl << "~~Note added~~";
      Note("Weapon is a common kitchen knife");
      r0p2 = true;
    }
    else if(i == 2 && r0p3 == false){
      cout << endl << endl << "~~Note added~~";
      Note("Killer came from the kitchen");
      r0p3 = true;
    }
  }
  else if(room == 1){
    if(i == 0 && r1p1 == false){
      cout << endl << endl << "~~Note added~~";
      Note("No sign of forced entry");
      r1p1 = true;
    }
    else if(i == 1 && r1p2 == false){
      cout << endl << endl << "~~Note added~~";
      Note("No sign of robbery");
      r1p2 = true;
    }
  }
  else if(room == 2){
    if(i == 0 && r2p1 == false){
      cout << endl << endl << "~~Note added~~";
      Note("Murder weapon came from the apartment, killer improvised");
      r2p1 = true;
    }
    else if(i == 1 && r2p2 == false){
      cout << endl << endl << "~~Key evidence added~~";
      KeyNote("Killer is left handed");
      r2p2 = true;
    }
  }
  else if(room == 4){
    if(i == 2 && r4p3 == false){
      cout << endl << endl << "~~Note added~~";
      Note("Todd Green 555-9021");
      r4p3 = true;
    }
  }
  else if(room == 6){
    if(i == 0 && r6p1 == false){
      cout << endl << endl << "~~Note added~~";
      Note("The body has not been moved");
      r6p1 = true;
    }
    else if(i == 1 && r6p2 == false){
      cout << endl << endl << "~~Key evidence added~~";
      KeyNote("Killer was wearing hiking boots");
      r6p2 = true;
    }
  }
  else if(room == 8){
    if(i == 1 && r8p2 == false){
      cout << endl << endl << "~~Key evidence added~~";
      KeyNote("John Trents is wearing hiking shoes");
      r8p2 = true;
    }
    else if(i == 2 && r8p3 == false){
      cout << endl << endl << "~~Key evidence added~~";
      KeyNote("John Trent's statement is inconsistent with facts");
      r8p3 = true;
    }
  }
  cout << endl;
}
//_______________________________________________________________KeyNote
void Player::KeyNote(string i){
  knotepad += "• ";
  knotepad += i;
  knotepad += "\n";
}
//_______________________________________________________________Note
void Player::Note(string i){
  notepad += "• ";
  notepad += i;
  notepad += "\n";
}
//_______________________________________________________________Notepad
void Player::Notepad(){
  cout << knotepad;
  cout << notepad;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++End of Class
vector<int> House[10]; // creates matrix of house paths
vector<Room> Rooms; // creatse list of rooms

void CLEAR(); // clears screen
void GenHouse(); // Generates house layout using Adj Matrix of vectors
void Fill(int i); // Fills each rooms strings
void UI(); // main game function
void Opening(); // Intro sequence / set player room index
void Walk(); // walk choice function
void Investigate(); // investigate choice function
void Notes(); // check notes choice function
bool Accuse(); // accuse choice function
//****************************************************************************************Main
int main(){srand(time(NULL));
  GenHouse(); // call to generate house
  Opening(); // intro sequence / set player room index

  UI(); // main game recursion

  cout << "\n\n                                                GAME OVER" << endl << endl;

  return 0; 
} 
//-----------------------------------------------------------------------------------Functions
//-------------------------------------------------------------------------------UI
void UI(){
  string choice;
  bool end = false;

  cout << "\n________________________________________________________________________________________________________" << endl;
  cout << "What would you like to do?\n[1]:Walk\n[2]:Investigate\n[3]:Check Notes\n[x]:Accuse\n>>ENTER:";
  cin >> choice;
  cout << endl;

  if(choice == "1"){ // Walk
    for(int i = 0; i < House[player.roomindex()].size(); ++i){
      cout << "[" << i+1 << "]: " << Rooms[House[player.roomindex()][i]].name << endl;
    }
    Walk();
  }

  else if(choice == "2"){ // Investigate
    cout << Rooms[player.roomindex()].poi;
    cout << "[x]:Go Back" << endl;
    Investigate();
  }

  else if(choice == "3"){ // Check Notes
    Notes();
  }

  else if(choice == "x" || choice == "X"){ // Accuse
    CLEAR();

    cout << endl << "Here's the evidence you've collected so far:" << endl << endl;
    Notes();

    end = Accuse();
  }

  else{
    cout << "\n" << choice << " is not a valid option" << endl;
    UI();
  }

  if(end == false){
    UI();
  }
}
//-------------------------------------------------------------------------------Walk
void Walk(){ // walk choice function
  string c;
  int cc;

  cout << ">>ENTER:";
  cin >> c;

  cc = stoi(c) - 1;
  if((cc < 0) || (cc > House[player.roomindex()].size())){
    cout << "\n" << c << " is not a valid option" << endl;
    Walk();
  }

  player.Walk(House[player.roomindex()][cc]);

  CLEAR();
  cout << Rooms[player.roomindex()].title;
  cout << Rooms[player.roomindex()].desc;
}
//-------------------------------------------------------------------------------Investigate
void Investigate(){ // investigate choice function
  string c;
  int cc;

  cout << ">>ENTER:";
  cin >> c;

  if(c != "x" && c != "X"){ // go back
    cc = stoi(c) - 1;
    if(cc < 0 || cc > 4){
      cout << "\n" << c << " is not a valid option" << endl;
      Investigate();
    }

    CLEAR();
    player.Investigated(Rooms, cc);
  }
}
//-------------------------------------------------------------------------------Notes
void Notes(){ // check notes choice function
  player.Notepad();
}
//-------------------------------------------------------------------------------Accuse
bool Accuse(){ // accuse someone recursive loop
  string accuse;

  cout << endl << "Who killed Lilly North?" << endl;
  cout << "[1]:Jeremy Cort\n[2]:John Trents\n[3]:Abby Small";
  if(player.evidence(1) == true){
    cout << "\n[4]:Todd Green";
  }

  cout << "\n[x]:Go Back\n\n>>ENTER:";
  cin >> accuse;

  if(accuse == "1"){ // jeremy cort - bad
    CLEAR();
    cout << "You approach the witness and level your accusation. You are met with a look of utter disbelief and confusion, and your confidence falters. When asked how you could possibly think that, you try to explain yourself, but even as you speak you can hear things not adding up. You trail off in the middle of a sentence, then just turn and walk away. All the way to your car. You get in and turn the engine on, and you just drive away. They were right, you think. Right to suspend you, to not trust you. You can't do this job anymore. It's too much, you realize. And it's been too much for far too long. Your phone rings. You roll down your window, pull the phone from your pocket and hurl it into the night. You don't know where you're going, you just drive.";
    return true;
  }

  else if(accuse == "2"){ // john trents - (0)bad - (>0)good - (max)best
    CLEAR();

    if(player.evidence(2) == true){ // best end
      cout << "You get the attention of a young patrol officer standing idly but trying to look busy, flipping through his notebook. You tell the rookie that you want help in making the arrest. He stares at you, bright eyed, and asks what you found." << endl;
	    cout << "'Well,' you begin, 'we have blood spatter cast-off showing the killer is left handed, John Trents is left handed. We have footprints in the victim's blood belonging to a man's hiking boot, John Trents is wearing hiking boots. And while that is enough reasonable suspicion to bring him, he's also given a very inconsistent account of what happened here tonight. Like claiming the killer ran out of the apartment without stopping, when the evidence shows he wiped his feet on the mat. He also claimed the victim was looking out the doorway when she went down, but the evidence shows she faced into the kitchen the entire time.'" << endl;
	    cout << "When the officer makes the arrest, John loses it. He begins screaming about women and rejection and how she promised him a second date. You look over at Abby and see the blood drain from her face as she crumples to the ground in disbelief and guilt." << endl;
	    cout << "Before they close the door on the squad car you approach. 'Why'd you stay, John? You could have run, you might have lost us in those woods. All the creeks and streams, we may never have found you. Why'd you stay?'" << endl;
	    cout << "Clarity comes to John's face as he absorbs your question, and with complete and terrifying honesty he answers." << endl;
	    cout << "'I wanted to watch. I wanted to watch them take her away. I wanted to follow her corpse to wherever they took it. I wanted to be there, at the crematorium, to watch her burn. She deserved it. She deserved.' He repeats the last line like a mantra and you step back to close the door." << endl;
	    cout << "Just like always, you feel happy for the briefest second, glad to have another horrible person taken out of the general population. But the sadness always follows. Another life, taken for no good reason, sacrificed for nothing more than a man's ego." << endl;
	    cout << "You did your job well, detective. A thorough investigation with a pile of evidence and a confession. Your confidence is restored, as is your superiors' belief in you." << endl;
    }

    else if(player.evidence(0) == true){ // good end
      cout << "You get the attention of a young patrol officer standing idly but trying to look busy, flipping through his notebook. You tell the rookie that you want help in making the arrest. He stares at you, bright eyed, and asks what you found." << endl;
	    cout << "'Well,' you begin, 'not too much yet, but I've got a hunch and just enough evidence to take the guy in for questioning. Come on.'" << endl;
	    cout << "As you approach John with the officer in tow the large man shifts uncomfortably. As you speak with him the rookie and a couple other nearby uniforms, picking up on the situation, close in around the two of you." << endl;
	    cout << "'I don't get it, John. Why'd you do it? And on top of that, why did you stay? You could have run off into those woods and we might never have found you.'" << endl;
	    cout << "'I don't know what you're talking about,' the man snarls." << endl;
	    cout << "You explain your evidence and fear begins to fill John's eyes." << endl;
	    cout << "'We've got enough to take you in for questioning, John. And I'm certain we'll find more in there. The crime scene guys are on the way and they will find every fiber, every print, every tell-tale blood drop. You're done.' Not the first time you've bluffed this hard, but you know if you don't trust your gut now you'll never get your confidence back." << endl;
	    cout << "John lunges at you in anger, but the cops circled around him catch and restrain him before he reaches you. He stops resisting and stares you down as he describes how he did it." << endl;
	    cout << "'She canceled our date,' you've heard this tone before, he's justifying what he's done and thinks he can convince you to justify it too. 'She set it up and then she canceled it. So I showed up anyway. She let me drop her off on our first date, so it's not like I didn't know where to go. She opened up the door and I made up some sob story and she let me in. I tried to talk to her, convince her to give me another chance, but she wasn't hearing. Stupid. Well I wasn't hearing it either. I grabbed that knife and I stabbed her and you know what? It felt good. It felt great. She can't reject me now, can she?'" << endl;
	    cout << "As the killer begins to laugh a pair of officers ratchets handcuffs onto his wrists. You read the man his rights." << endl;
	    cout << "'Well done, detective.'" << endl;
    }

    else if(player.evidence(0) == false){ // good/bad end
      cout << "You approach the witness and level your accusation. He laughs in your face and asks what evidence you have to justify an arrest. You are forced to admit you do not have it, just a gut instinct. He laughs again and walks away. The nearby officers avert their eyes, they look embarrassed for you. And for good reason, it turns out. The Chief of Police taps you on the shoulder. You're off the case, detective. Maybe you need more time…" << endl;
    }
    return true;
  }

  else if(accuse == "3"){ // abby small - bad
    CLEAR();
    cout << "You approach the witness and level your accusation. You are met with a look of utter disbelief and confusion, and your confidence falters. When asked how you could possibly think that, you try to explain yourself, but even as you speak you can hear things not adding up. You trail off in the middle of a sentence, then just turn and walk away. All the way to your car. You get in and turn the engine on, and you just drive away. They were right, you think. Right to suspend you, to not trust you. You can't do this job anymore. It's too much, you realize. And it's been too much for far too long. Your phone rings. You roll down your window, pull the phone from your pocket and hurl it into the night. You don't know where you're going, you just drive.";
    return true;
  }

  else if(accuse == "4" && player.evidence(1) == true){ // todd green - bad
    CLEAR(); 
    cout << "You slip your phone from your pocket and dial the number on the crumpled piece of paper again. This time a man answers with an annoyed tone. You begin with your accusation, telling Mr. Green that you're on to him and that there's no where to run. He tries to interrupt several times but you talk over him, adamant that you've got your guy. When Todd can finally get a word in he asks who it is he is supposed to have killed, and tells you he doesn't recognize Lilly's name. He informs you that, given his profession as an exotic cat breeder, several women in the tri-state area have his name and number written down somewhere. On top of that, Todd himself is on vacation in Bali, and gives you the telephone number to the hotel he is currently in, as well as his room number, so that you can verify his alibi. He then hangs up. As you lower your phone you see the other officers staring at you in silence. You jumped the gun detective. You had no real evidence and you trusted your gut, and your gut was dead wrong. There's no way the brass doesn't hear about this. You head to your car. Might as well leave, there's nothing left for you here." << endl;
    return true;
  }
  else if(accuse != "x" && accuse != "X"){ // go back
    Accuse();
  }

  return false;
}
//-------------------------------------------------------------------------------CLEAR
void CLEAR(){ // clears screen
  cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
  cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
  cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
  cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
  cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
  cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
  cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
  cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
  cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
  cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
}
//-------------------------------------------------------------------------------GenHouse
void GenHouse(){ // Adj List to house / parallel vector of room index'
  int paths[] = {9, 9, 3, 3, 3, 3, 9, 9, 9, 9}; // array of how many rooms are linked to a a single room
  for(int i = 0; i < 10; ++i){ // loop through each room
    if(i > 5){ // if not attached to interior rooms
      House[i].push_back(0); // push body
      House[i].push_back(1); // push living room
      for(int ii = 6; ii <= paths[i]; ++ii){ // link outside rooms together
        if(ii != i){
          House[i].push_back(ii);
        }
      }
    }
    else{ // if interior rooms
      for(int ii = 0; ii <= paths[i]; ++ii){ // link interior rooms to living room and body
        if(ii != i){
          House[i].push_back(ii);
        }
      }
    }
    Rooms.push_back(Room());
  }

  for(int i = 0; i < Rooms.size(); ++i){ // fills parallel vector with strings of rooms
    Fill(i);
  }
}
//-------------------------------------------------------------------------------Fill
void Fill(int i){
  if(i == 0){ // room 0 - body
    Rooms[i].index = i;
    Rooms[i].name = "Body";
    Rooms[i].title = "                                               == Body ==\n\n";
    Rooms[i].desc = "You nod at the coroner and she pulls back the sheet covering the victim. Most of the evidence of the act itself seem to be contained to this part of the living room. You see several evidence markers placed next to the body, and nearby lies a bloody knife.";
    Rooms[i].poi = "\nWhat would you like to investigate further?\n[1]:Victim\n[2]:Murder Weaopn\n[3]:Position of Body\n";
    Rooms[i].poi1 = "The deceased appears to be a woman in her mid forties. She is blond and petite, nicely but inexpensively dressed in a pair of fitted jeans and a sequined top. She is still wearing jewelry. Blood covers most of her torso and head, seemingly coming from a grievous wound on the right side of her neck, clearly severing the carotid. You see no purse next to the woman and check her pockets. You find her phone in a one back pocket, screen still locked. In the other back pocket you find a slim wallet containing only a single twenty dollar bill, a credit card, and the victim's ID. Her name was Lilly North.";
    Rooms[i].poi2 = "Your instinct tells you that this knife must be the murder weapon. It is a common enough kitchen knife, you suspect you may even own this model yourself. The blade is thoroughly covered in blood, but the handle has clearly been wiped clean. With a  gloved hand you lift the handle of the knife for a closer look. Streaks. The handle was cleaned in a hurry.";
    Rooms[i].poi3 = "The victim's body lies crumpled on the floor, next to the couch, with her head near the door and her feet pointing into the kitchen. Based on this, you believe the attacker came from the kitchen. Judging by the blood smears on the floor, it appears as though the victim was stabbed while standing, struggled for a few steps, then fell, bleeding out quickly. She does not appear to have been moved.";
  }

  else if(i == 1){ // room 1 - living room
    Rooms[i].index = i;
    Rooms[i].name = "Living Room";
    Rooms[i].title = "                                           == Living Room ==\n\n";
    Rooms[i].desc = "The location of the victim and apparent murder scene. The open floor plan connects the kitchen to the living room with no separating wall. You see a couch, a coffee table, a small desk, and a TV on a stand.";
    Rooms[i].poi = "\n[1]:Front Door\n[2]:Electronics\n[3]:Couch\n";
    Rooms[i].poi1 = "\nThe only entrance to the apartment. Bloodied footprints make a fading trail from the body to the welcome mat, where the assailant apparently wiped his feet before stepping off. There is no sign of blood on the front step. The doorknob is still in place and there are no signs of a forced entry on either the lock or the door jamb."; 
    Rooms[i].poi2 = "\nIn the room you can see a personal computer sitting on a small desk, a large, expensive looking television, and a formidable number of Blu-rays lined up neatly in a tall bookcase. Nothing seems to be missing or disturbed."; 
    Rooms[i].poi3 = "\nThe red leather couch is slightly askew, likely that either the victim or the attacker bumped into it during the struggle. You can only just see a line of blood stretching across the couch itself. Pointing it out to the coroner, she tells you it is almost certainly arterial spray from the initial stab wound, while the victim still stood.";
  }

  else if(i == 2){ // room 2 - kitchen
    Rooms[i].index = i;
    Rooms[i].name = "Kitchen";
    Rooms[i].title = "                                              == Kitchen ==\n\n";
    Rooms[i].desc = "The kitchen, much like the living room, is tidy and only lightly furnished. You can see a knife block on the counter. The refrigerator stands out as the only messy thing in sight, with notes stuck to it haphazardly. There is some blood on the ceiling, originating near the body in the living room but mostly stretching into the kitchen itself.";
    Rooms[i].poi = "\n[1]:Knife Block\n[2]:Ceiling\n[3]:Refrigertor\n";
    Rooms[i].poi1 = "Inspecting the knife block on the kitchen counter you can see that a single knife is missing. The same brand as the knife found next to the body. Judging by sight, the apparent murder weapon would fit the slot of the missing knife perfectly.";
    Rooms[i].poi2 = "Looking up, you notice a streak of blood droplets across the kitchen ceiling. You get the coroner's attention and point at what you see. She stares at the droplets for a minute, then tells you with confidence that they were made by cast-off, and that it's likely the killer was left handed judging by the direction of the cast-off itself.";
    Rooms[i].poi3 = "The refrigerator is covered in magnets and scrap pieces of paper. Reading through the notes you mostly just find grocery lists and appointment reminders. One note stands out, however. 'Blind date on Tues.!' Yesterday was Tuesday. It could be something, but there's no way to know which Tuesday she meant.";
  }

  else if(i == 3){ // room 3 - closet
    Rooms[i].index = i;
    Rooms[i].name = "Closet";
    Rooms[i].title = "                                              == Closet ==\n\n";
    Rooms[i].desc = "Next to the front door is a small hall closet. This is apparently where the victim kept her linens, jackets, and a small fireproof safe.";
    Rooms[i].poi = "\n[1]:Linens\n[2]:Jackets\n[3]:Safe\n";
    Rooms[i].poi1 = "\nYou see towels, sheets, and extra blankets, but nothing seems to be out of place or missing. There is nothing of note here.";
    Rooms[i].poi2 = "\nYou fish around in the pockets of the jackets hanging in the closet. A few cough drops, a couple of pens, and several crumpled papers. The papers appear to just be notes and reminders pertaining to the victim's work. ";
    Rooms[i].poi3 = "\nYou pull the fireproof safe down from its shelf. The victim's keys are on a hook inside the closet, and you spot a tiny key that may fit the safe's lock. Opening the safe you find important paperwork; birth certificate, lease agreement, car title, a birthday card signed 'All my love, Gramma', and various other typical papers. The lock shows no signs of tampering and you feel no reason to believe anything is missing.";
  }

  else if(i == 4){ // room 4 - bathroom
    Rooms[i].index = i;
    Rooms[i].name = "Bathroom";
    Rooms[i].title = "                                             == Bathroom ==\n\n";
    Rooms[i].desc = "The bathroom is pleasant and surprisingly spacious. Brightly decorated in blues and greens, it is tidy and well kept. The counter is well organized, with only a handful of beauty products on display. The rest, you assume, is tucked away in the medicine cabinet and the drawers and cabinets under the sink. You also spot a half-full tiny trash can near the toilet.";
    Rooms[i].poi = "\n[1]:Medicine Cabinet\n[2]:Drawers and Cabinet\n[3]:Trash Can\n";
    Rooms[i].poi1 = "\nInside you find a few bottles of over the counter pain medicine, a toothbrush, a bottle of expensive perfume, and a pair of reading glasses. Nothing of note here.";
    Rooms[i].poi2 = "\nIn the drawers you find a modest supply of makeup and beauty tools. Nothing surprising in the cabinets either; just typical things you are likely to find in most women's bathrooms.";
    Rooms[i].poi3 = "\nOn top of the wadded up tissue lies a crumpled pastel pink note. It says simply 'Todd Green 555-9021'. You call the number but it just rings and rings, never going to voicemail. You bag the note as evidence, knowing the tech guys are already out for the night and won't be able to process it until tomorrow morning.";
  }

  else if(i == 5){ // room 5 - bedroom
    Rooms[i].index = i;
    Rooms[i].name = "Bedroom";
    Rooms[i].title = "                                              == Bedroom ==\n\n";
    Rooms[i].desc = "Like the rest of the apartment, the bedroom is tidy. The bed is unmade, but only slightly rumpled. A large dresser sits opposite the foot of the bed. A night stand with two drawers and a small lamp atop it sits next to the bed.";
    Rooms[i].poi = "\n[1]:Bed\n[2]:Dresser\n[3]:Nightstand\n";
    Rooms[i].poi1 = "\nUnmade, but only lightly slept in. It's a queen size bed, but only the side near the door is untucked. It seems likely that she slept alone the previous night.";
    Rooms[i].poi2 = "\nYou never really like this part, rummaging through people's drawers. Unfortunately though, people like to hide their secrets there. This victim is no different. You find a sturdy picture frame face down under some clothes. The picture in the frame is that of the victim when she was younger with a man. They look happy, smiling into the camera with a snow-capped mountain in the distance behind them. You take the picture out of the frame, hoping to find names or dates on the back, but there is nothing there.";
    Rooms[i].poi3 = "\nYou find a self-help book in the top drawer of the nightstand titled 'Dating in Your Forties- Making the Best of the New Best Years'. The bookmark is just a tad past halfway. There is no dedication or note in the cover. It looks like the victim was trying to re-enter the dating world.";
  }

  else if(i == 6){ // room 6 - coroner
    Rooms[i].index = i;
    Rooms[i].name = "Coroner";
    Rooms[i].title = "                                              == Coroner ==\n\n";
    Rooms[i].desc = "You greet the coroner, a grim looking woman with years of experience drawn in lines on her face. She glances up from her chart to give you the rundown of what she knows so far. Cause of death appears to be multiple stab wounds, though she suspects only the neck wound was fatal with the others more superficial. Time of death estimated at around 21:00, corresponding with the 911 calls.";
    Rooms[i].poi = "\nWhat would you like to ask the coroner?\n[1]:'What can you tell me about the blood spatter?'\n[2]:'There are a lot of bloody footprints here, what do you make of them?'\n[3]:'Are there any injuries in addition to the stab wounds?'\n";
    Rooms[i].poi1 = "\nThe coroner points at the blood near the body.\nThe large drops in the area around the victim's feet indicate she stood there when she suffered her first wound, likely the one to her neck.\nThe puddle around her head and upper torso show that she died there and has not been moved.\nSee these lines extending from the puddle, away from the victim's face? Textbook arterial spurting.\nJudging by the how short the spray is, she had already experienced significant blood loss before she hit the ground.";
    Rooms[i].poi2 = "\n'Well, most of the prints are concentrated here, relatively close the victim's feet. See the pattern on her soles? Pretty identifiable waffle pattern, which you can see in these prints. Looks like she was taking small backward steps. There's also a larger set of prints here. My instinct says it's a man's shoe. From the apparent pattern and wear on the tread, I would guess hiking boot. Unlike the deceased, these footprints lead out of the apartment, fading with every step.''";
    Rooms[i].poi3 = "\n'No signs of sexual assault. No signs of any blunt force trauma either. No punching or strangling or anything other than stabbing.\nThere are some deep cuts along her hands and forearms, so she tried to defend herself. I can let you know more after the autopsy, but it looks to me like she was surprised. Poor thing never had a chance.'";
  }

  else if(i == 7){ // room 7 - witness #1
    Rooms[i].index = i;
    Rooms[i].name = "Bloody Male #1";
    Rooms[i].title = "                                            == Jeremy Cort ==\n\n";
    Rooms[i].desc = "This man's hands are covered in blood. As you greet him he simply stares into the middle distance and nods. You have to repeat your first question before he snaps out of it and begins to speak with you.";
    Rooms[i].poi = "\n[1]:'What is your name and how do you know the victim?'\n[2]:'What happened here? Did you see anything?'\n[3]:'Can anyone verify that you were in the apartment when the shouting started?'\n";
    Rooms[i].poi1 = "\n'Uh, I'm Jeremy Cort. I live next door. I didn't really know Lilly very well. I had to bring her some mis-delivered mail a few times. She seemed so sweet. Why would anyone do that?'";
    Rooms[i].poi2 = "\n'Um, I was watching the basketball game and I heard Lilly shout. I was, well, I was annoyed at first. I mean, I looked up and missed a play. But then she shouted again and I realized something was wrong. I threw on some shoes and ran outside.' You glance at the man's shoes and see that they are generic sneakers, laces undone, no visible blood. 'By the time I got to her door it was already over. I saw that guy over there,' he points to the other male witness, 'run in. He tried to help her, but… but the blood… it was just, I don't know, just gushing out. I came in and tried to put pressure on the wound but she was just… there was just nothing… nothing I could do.'";
    Rooms[i].poi3 = "\n'N-no. I live alone. I posted something on Twitter a minute or two before it happened, but no.' He pulls out his phone, holding it in his left hand and unlocking it with his thumb. He shows you the tweet, some nonsense about basketball that you don't really understand.";
  }

  else if(i == 8){ // room 8 - witness #2
    Rooms[i].index = i;
    Rooms[i].name = "Bloody Male #2";
    Rooms[i].title = "                                            == John Trents ==\n\n";
    Rooms[i].desc = "This man's hands are covered in blood, and there are streaks of blood on his face that he has apparently tried to wipe off. He extends his left hand for a handshake as you introduce yourself. He appears be well composed, and answers your questions clearly and promptly.";
    Rooms[i].poi = "\n[1]:'What is your name and how do you know the victim?'\n[2]:'Can anyone verify that you were on a walk outside when the shouting began?'\n[3]:'Describe what you saw.'\n";
    Rooms[i].poi1 = "\n'John Trents. I don't know her. I was just on a walk and I heard screaming and saw a guy run out of this apartment. I saw the woman with her hand on her neck and when she turned around to face me she crumpled to the ground. I ran inside to try and help her but, well, you know. Some of her blood sprayed into my face. Am I going to need to get tested or something?' You assure the man that you will have paramedics check him over.";
    Rooms[i].poi2 = "\n'What? No, of course not. I hike through the woods here all the time.' You glance at the man's feet and notice that he is in fact wearing hiking shoes, though they seem to be wet. It's hard to tell in the fading light whether they are wet with blood or dew.";
    Rooms[i].poi3 = "\n'I was walking by, saw a man run out of the apartment, then heard a scream. I looked in the apartment and saw the woman on the floor. I mean falling. I saw her fall to the floor. That's it.' You ask the man for a description of the person he saw fleeing the scene. 'I don't know. Average weight, average height, he was wearing all black with white sneakers and a mask. He ran out the door and into the woods. You should probably get those scent dogs out there.'";
  }

  else if(i == 9){ // room 9 - witness #3
    Rooms[i].index = i;
    Rooms[i].name = "Distressed Female";
    Rooms[i].title = "                                            == Abby Small ==\n\n";
    Rooms[i].desc = "A woman, likely in her thirties, sits in the grass near the street. An officer is kneeling next to her, a reassuring hand on her shoulder. The woman looks up as you approach, and stands to speak with you. She seems eager to help.";
    Rooms[i].poi = "\n[1]:'Who are you and how do you know the victim?'\n[2]:'Tell me what happened here.'\n[3]:'What can you tell me about the victim? Angry ex-boyfriend? Disgruntled lover?'\n";
    Rooms[i].poi1 = "\n'I'm Abby Small, I live on the other side of Lilly. We weren't, like, best friends or anything, but we would chat every few days. I really can't believe this happened. She is just so nice and sweet.'";
    Rooms[i].poi2 = "\n'Well, I had music on in my place so I didn't hear anything. Not until the sirens. I came out to see what was going on and, well, I saw more than I ever wanted to. Poor Jeremy, he looks so traumatized.' You follow up with a question about seeing anyone fleeing the scene, but she claims to have only the other two men.";
    Rooms[i].poi3 = "\n'Well, she got out of a long term relationship about a year ago. It was an amicable split, I guess, but she was still heartbroken for a while. She was just starting to date again recently. I even helped her make a profile on Tinder. She had a date last night, I talked to her when she got home. She said the dude was weird, that he stared at her through the entire meal. She actually talked about going on a second date with the guy, but I talked her out of it. Trust your gut, you know. I insisted she message him to cancel. He seemed to take it well enough.' You ask if she recalls the man's name. Her brow furrows as she thinks, but eventually tells you she isn't certain, but she's pretty sure it started with a J or a G.";
  }
}
//-------------------------------------------------------------------------------Opening
void Opening(){
  bool check = false;
  string choice;
  char exit;

  cout << endl; // opeing dialogue
  cout << "You are detective Arthur Stanton, an accomplished crime solver. ";
  cout << "You are famous among your peers for your impressive percentage of closed cases, infamous among the brass for being rash and reckless. ";
  cout << "This is your first case back from a prolonged suspension, and you know that if you want to stay on the force you need to close this case fast and clean." << endl << endl;
  cout << "You arrive at the scene of a suspected murder in a quiet apartment belonging to one, Lilly North. ";
  cout << "In front of the apartment you see several patrol cars parked, their lights spinning silently and the coroner's van pulled up just behind them. ";
  cout << "An ambulance is also on scene, the paramedics milling about idly. ";
  cout << "Uniformed officers are standing with three individuals you assume to be witnesses. ";
  cout << "Two of them are men with blood on their clothes, the third is a woman visibly upset and trying unsuccessfully to stifle tears. ";
  cout << "The front door is open and you poke your head inside, quickly scanning the scene. ";
  cout << "A body lies under a white sheet next to the couch. ";
  cout << "Blood everywhere, a disturbing mess in an otherwise impeccably tidy apartment." << endl; 

  do{
    cout << "\n________________________________________________________________________________________________________" << endl;
    cout << "What would you like to investigate first?" << endl;
    cout << "[1]:Body\n[2]:Apartment\n[3]:Coroner\n[4]:Witnesses" << endl;
    cout << "\n>>ENTER:";
    cin >> choice;

    if(choice == "1"){ // Body
      player.Walk(0);
      check = true;
    }
    else if(choice == "2"){ // Apartment
      player.Walk(1);
      check = true;
    }
    else if(choice == "3"){ // Cornoer
      player.Walk(6);
      check = true;
    }
    else if(choice == "4"){ // Witnesses
      int w = rand()%(9-7+1)+7; // Generate the number, between 7 and 9.
      player.Walk(w);
      check = true;
    }
    else{ // checks input
      cout << "\n" << choice << " is not a valid option" << endl;
      cin.clear();
    }
  }while(check == false);

  CLEAR();
  cout << Rooms[player.roomindex()].title;
  cout << Rooms[player.roomindex()].desc;
}