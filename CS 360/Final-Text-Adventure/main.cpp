//TextAdventure.txt -- Adventure awaits in the world of Monster Hunter

//10/27/2017 - 12/11/2017

//Create a "simple" text based adventure game. The game will be comprised of Room() objects. 
//These objects will have a room_name,

//room_description, room_id, occupied code, and 4 exit codes (N, S, E, W). 
//You are free to add other variables as necessary. 
//The exit codes will contain the room_id of the room in that direction. 
//If the room is occupied, randomly select one of 4 monsters to spawn in the room.
//The monsters are instances of the Monster() class. 
//What, exactly, they do with your character is up to you.

// Move throughout the adventure with the N,S,E,W keys (moving you in the four cardinal directions.)
// Display room_title and room_description the first time the player enters the room.
// Only display the room_title with subsequent visits to the room, unless the player enters the ’L’ook key.
// When a room is occupied spawn a monster.
// Create a minimum of 5 rooms in your dungeon.
// Perform input validation with the command options.

// Bonus 1 - Line 128: multiple maps
// Bonus 2 - Line 251: inventory system
// Bonus 3 - Line 584: combat
// Bonus 4 - Line 693: picture map
// Bonus 5 - Line 79 - 93: Misc gameplay enhancements

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

// struct for room blueprint
struct Rooms 
{
  int RoomNum; // rooms number
  string Desc; // description of room
  string Look; // describes creatures, resources, and paths
  vector<int> Door = {99, 99, 99, 99, 99}; // doors out of room
  bool Mon = false; // if monster is in that room (default false)
};

int Location = 0; // the map 
int Area = 0; // the room
string Zone; // the map name
bool Hunt = true; // if hunt is still in progress
bool RanAway = false; // if monster ran away at one point
string MonsterName; // name of currently hunting monster
int Potion = 3; // # of potions to heal

struct PlayerStat // player stats
{
  int HealthP = 200; // player health
  int AttackP = 0; // player attack damage
  int DefenceP = 80; // player defence stat
  int DodgeP = 25; // player dodge rate
};

struct MonsterStat // monster stats
{
  int HealthM = 1685; // monster health
  int AttackM = 90; // monster attack damage
  int DefenceM = 100; // monster defence stat
  int DodgeM = 15; // monster dodge rate
};

// array of rooms to make a map
Rooms *JurassicFrontier = new Rooms[12]; // 0
Rooms *Dunes = new Rooms[12]; // 1

PlayerStat *PlayerS = new PlayerStat;
MonsterStat *MonsterS = new MonsterStat;

// array of maps to choose from
Rooms Map[2][12] = {*JurassicFrontier, *Dunes}; // array of struct arrays

void PickMap(); // picks a random map
void FillMap(); // fills maps with their respective data
  void Fill_JurassicFrontier(); // fills the description and doors portion
  void Fill_Dunes(); // fills the description and doors portion

void Gear(); // sets player fight class and gear

void UI(); // shows UI for look, inventory, choose path, etc.
  void Combat(); // combat with the Nargacuga
      void CombatM(); // enemy move
    int Calc(int, int, int); // calculates damage delt post armors
  void InvUI(); // UI for inventory / stats / and gather resources
  void MapRoute(); // cout the map
  void NextArea(); // moves player to next area of choosing
void PlaceMon(); // picks random name of monster and picks the Area the monster is in
void CheckMonster(); // checks if monster bool is true, if so cout 


//*****************************************************************************************************************Main
int main()
{
  //srand (11));
  
  PickMap(); 
  FillMap();
  PlaceMon();
  
  for(int i = 0; i < 11; ++i)
  {
    if(Map[Location][i].Mon == true)
    {
      cout << i << endl;
      cout << MonsterName << endl;
    }
  }
  
  cout << "____________________*" << Zone << "*____________________" << endl << endl;
  
  cout << "Welcome hunter to the " << Zone << 
          ".\nRight now we are in the base camp, Area 0.\n" << 
          "Oh thats right! I havent introduced myself yet,\n" <<
          "I'm Sophia, and I'm your guildmarm for this hunt,\n\n" <<
          "I give you tips on where to find the <" << MonsterName << "> you'll be hunting\n" <<
          "as well as information on items you can pick up.\n\n" <<
          "But before we get on with it, you need to pick out what weapon you'll be hunting with\n\n";

  Gear();

  cout << "\nOne more thing, if you end up taking too much damage,\n" <<
          "dont be afraid to run away to use a potion or go to base camp to regain your helth.\n" <<
          "Well thats it for now, so get out there and get that monster!!" << endl << endl;
  
  while(Hunt)
  {
    UI();
  }
  
  return 0;
}

//=================================================================================================================Functions
//-----------------------------------------------------------------------------------------------------------------PickMap
void PickMap()
{
  Location = rand() % 2;
  
  if(Location == 0)
  {
    Zone = "Jurassic Frontier";
  }
  else if(Location == 1)
  {
    Zone = "Dunes";
  }
}

//-----------------------------------------------------------------------------------------------------------------FillMaps
void FillMap() 
{
  if(Location == 0) // fills Jurrasic Fontier only
  {
    for(int i = 0; i < 12; ++i)
  {
    Map[0][i].RoomNum = i;
  }
  Fill_JurassicFrontier();
  }
  
  else if(Location == 1) // fills Dunes only
  {
    for(int i = 0; i < 12; ++i) 
  {
    Map[1][i].RoomNum = i;
  }
  Fill_Dunes();
  }
}

//_________________________________________________________________________________________________________Fill JurassicFrontier [0]
void Fill_JurassicFrontier()
{
  Map[0][0].Desc = "You are at base camp on the top of a cliff with a great view of the Jerrasic Frontier.\n\n";
  Map[0][1].Desc = "You're standing on a grass patch on the lip of a waterfall with the water flowing around, one stream falls off, continuing the waterfall, the other flowes inland.\n\n";
  Map[0][2].Desc = "You're in a forest basin surrounded by trees and rocks, a creek from the waterfall runs through to a cavern.\n\n";
  Map[0][3].Desc = "A large ancient cave carved from the river that flowed through here engulfes you and mesmerizes you with glimmering minerals and fossiles in its walls.\n\n";
  Map[0][4].Desc = "A dense forest with towering trees that nearly block out all the sunlight, a few rays poke throug.\n\n";
  Map[0][5].Desc = "You enter a clearing and see that there seems to be remnants of an old base camp that is now in ruins, at the endge of the cliff you have a great view towards Area 8 with some vines down to it.\n\n";
  Map[0][6].Desc = "You stand in large expansive plains, you can see the tree line of the Jurrasic forest as well as the mountain the base camp and Sophia is on.\n\n";
  Map[0][7].Desc = "You stand in a large cave with only a few beams of light, though enough for plant life to flourish spectacularly along the walls and from a small opening in the ceiling where a waterfall rushes through.\n\n";
  Map[0][8].Desc = "You are on the edge of a tall cliff outside of Area 7, the ground is littered with bones and old carcases, most likely hunts from a wyvern.\n\n";
  Map[0][9].Desc = "A lush patch of grass and leaves surround you, little ponds of water can barley be seen through the thick vines which hang from the trees.\n\n";
  Map[0][10].Desc = "The ground is damp and soft, above you are huge mushrooms which emit a feint glow creating a mystical feeling in this deep part of the forest where sunlight cant reach,.\n\n";
  Map[0][11].Desc = "This is the deepest part of the Jurrasic Frontier, small pools of water form in the grass and fallen trees make the terrain rugged.\n\n";
  
  Map[0][0].Look = "There isnt much of interest here.\nThere is only one path down to [Area 1].\n\n";
  Map[0][1].Look = "There are some trees and plants but not much of interest.\nSome tall Larinoth grazing on the tops of the trees, but they arent what you're hunting.\nThere is a path to [Area 6] past the water,\na path to [Area 2] following the creek,\nand [Base 0] up the hill.\n\n";
  Map[0][2].Look = "There are some medicinal plants and rare bugs flying around.\nThere are some giant ant like Altaroth foraging some blue mushrooms by your feet.\nFollowing the creek up is [Area 1],\nthrough the trees is the big plains of [Area 6],\ndeeper in the forest is [Area 4],\nfollowing the creek ia a cave to [Area 3].\n\n";
  Map[0][3].Look = "Precious ore deposits litter the walls and a pond of fish is close by.\nA few Rhenoplos are herded together grazing on the vegitatoion, best to stear clear of them.\n Following the creek up is [Area 2],\nfurther in the cave is an opeing to [Area 7].\n\n";
  Map[0][4].Look = "There is a hive of bees with honey and some mushrooms.\nThere are some giant ant like Altaroth foraging some blue mushrooms by your feet.\nThere is a path through the forest to [Area 2],\nThe trees open up to the big open plains of [Area 6],\nthere is a clearing through the trees to [Area 5],\ninto a large open cavern is [Area 7].\n\n";
  Map[0][5].Look = "There are some old supply boxes which may contain something useful.\nSome Jaggi raptors seem to have moved in here, you should be carful.\nThere is a path to the plains of [Area 6],\nthrough the thick mess of trees is [Area 4],\nbelow the cliff is [Area 8].\n\n";
  Map[0][6].Look = "Large trees and some hunted creatures dot the land.\nSome Jaggi raptors are looking to take down a Larinoth that is grazing.\nYou can see the waterfall to [Area 1],\nthere are two paths into the forest,\n[Area 2] seems to be a bit more open\nwhile [Area 4] is much more dense,\na small rock path to [Area 8] can be seen in the distance.\n\n";
  Map[0][7].Look = "There are some ores in the walls and medicinal herbs, though you should be mindful of the wyverns nest just at the edge of the waterfall.\nSome Jaggi are present, no doubt trying to steal an egg or two from the wyverns nest.\nThe is a crack in the wall leading to the caverns of [Area 3],\nthe dense forest in [Area 4] is just past some trees,\na large opening in the cave to [Area 8].\n\n";
  Map[0][8].Look = "Some of the bones can bee scavanged and turned into gear.\nJaggi are around gnawing at the old bones for scraps.\nLong vines stetch down from [Area 5],\nthe mouth of the cave to [Area 7] stretches across the wall,\nfurther below is the deep basin of [Area 9].\n\n";
  Map[0][9].Look = "There are some trees and plants but not much of interest.\nA few Rhenoplos are herded together grazing on the vegitation, best to stear clear of them.\nUp some very long and sketchy vines is [Area 8],\n[Area 11] can be seen through some trees,\nthe roots of many mushrooms can be climbed to drop you into [Area 3],\na small path lines with glowing mushrooms can be seen to [Area 10].\n\n";
  Map[0][10].Look = "Rare mushrooms can be found all around you and a few glowing bugs.\nJaggi run around trying to catch some flying Bnahabra bugs.\nThrough a small path you see light to [Area 9],\nfollowing the mushrooms you see a path to [Area 11].\n\n";
  Map[0][11].Look = "Some valuable fossiles can be seen in a rock wall, and some honey bees hive by the trees.\nIn the calmness you see a few Gargwa nesting their eggs in the shade.\nA path leads to [Area 9],\na few glowing mushrooms line a small dark path to [Area 10].\n\n";
  
  Map[0][0].Door = {1};
  Map[0][1].Door = {0, 2, 6};
  Map[0][2].Door = {1, 3, 4, 6};
  Map[0][3].Door = {2, 7};
  Map[0][4].Door = {2, 5, 6, 7};
  Map[0][5].Door = {4, 6, 8};
  Map[0][6].Door = {1, 2, 4, 5};
  Map[0][7].Door = {3, 4, 8};
  Map[0][8].Door = {5, 7, 9};
  Map[0][9].Door = {8, 10, 11};
  Map[0][10].Door = {3, 9, 11};
  Map[0][11].Door = {9, 10};
}

//_________________________________________________________________________________________________________Fill Dunes [1]
void Fill_Dunes()
{
  Map[1][0].Desc = "You are at base camp in a rocky lookout point, the expansive dunes on one side and a rocky canyon on the other.\n\n";
  Map[1][1].Desc = "You are in a canyon corridor with a few plants dotting the edges.\n\n";
  Map[1][2].Desc = "You walk into a baren land of sand and tall dunes which make travel difficult.\n\n";
  Map[1][3].Desc = "You find yourself in an oasis with crystal clear waters and shady palm trees tucked away between the towering walls of the canyon.\n\n";
  Map[1][4].Desc = "This Area's walls are structured like terraces which you could climb; a pool of spring water and fish rests in the shade under a wall.\n\n";
  Map[1][5].Desc = "You are in a huge cavern with single spire of stone and what seems to be sand flowing like a river around it, the sand drifts straight off an edge into a gaping pit along with massive boulders that are carried with the sand.\n\n";
  Map[1][6].Desc = "You walk into a small cave with a hole where the sunlight pokes though, this shade provides a bit of respite from the sun and home to some vegitation.\n\n";
  Map[1][7].Desc = "A huge expansive wasetland of sand and rock, walls of stone surround the area blocking wind which makes this place still and seamingly dead with the exception of a small shore and one column of stone in the middle of this bowl.\n\n";
  Map[1][8].Desc = "You walk into a small cave with a hole where sunlight pokes though and a constant flow of sand, many ores which where washed down from above shine and project a spectacle of dancing lights on the walls of this cave.\n\n";
  Map[1][9].Desc = "You step foot into a small cave, this shade provides a bit of respite from the sun.\n\n";
  Map[1][10].Desc = "There is a pit of sand which is encompassed by a ring of stone that leades to other Areas.\n\n";
  Map[1][11].Desc = "You stumble onto a small camp of Meylynx cats, they made houses out of clay and holes in the walls and though the houses are far too small for you to enter they made quite a peacful community for themselves.\n\n";
  
  Map[1][0].Look = "There isn't much of interest here.\nThere are two paths, one through a rocky archway to [Area 2],\nand on into the canyon of [Area 1].\n\n";
  Map[1][1].Look = "There are a few herbs dotted along the walls which could be useful.\nThere are no creatures here.\nYou see a path headed down between two walls and the smell of fresh water from [Area 3],\nA path upwards heads to [Area 4],\nanother path down heads to [Base 0].\n\n";
  Map[1][2].Look = "There isnt much that can survive in this heat but you can see a few desert plants scattered around which may contain something useful.\nA few Cephalos sand sharks swim through the dunes with ease on the look out for their next prey.\nYou see the stone path leading up to [Base 0],\n[Area 7] is past a few miles of more baren sands,\nand a cave to which leads to [Area 6],\n.\n\n";
  Map[1][3].Look = "The water gives life to make fine herbs and berries, a few bugs can be found here too.\nA pack of Genprey raptors lounge around by the water and you can see small sand clounds from buried Hermitaur crabs.\nYou see two paths headed up hill in opposite directions, one to [Area 1],\nand the other to [Area 4].\n\n";
  Map[1][4].Look = "You see a small spring filled with fish and perhaps these terraces contain a few ore deposits.\nHugh turlte like Apceros are taking drinks from the spring and grazing on what little vegitation there is.\nAbove the terrace is the path to [Area 1],\nalong the shore of the sping is large crack in the wall leading to [Area 5],\nyou can see an opening to [Area 10].\n\n";
  Map[1][5].Look = "Some ore deposits have been unearthed by the constant chisleing of flowing sand.\nFew armored scorpion like Konchu hang on the walls and ceiling of this cavern.\nThere seems to be only one path out towards [Area 4], though perhaps the pit leads [Area 8]?.\n\n";
  Map[1][6].Look = "This cave has a cornucopia of medicinal herbs, rare bugs, mushrooms, and ore deposits all around.\nA few Meylynx cats are rumaging through the cave looking for shiny things as Vespoid mosquitos constantly pester them.\nThere is only one path back out to [Area 2].\n\n";
  Map[1][7].Look = "This Area is so barren a devoid of any resources.\nA few Cephalos sand sharks swim through the dunes with ease on the look out for their next prey.\nYou see two caves entrances to [Area 8] and [Area 9],\na path along the coast to [Area 10],\nand miles of barren sand to [Area 2].\n\n";
  Map[1][8].Look = "Many ores glimmer in the sand that washed them down here, but one stands out, a fully intact meteorite, which possibly made this giant pit where sand flows from.\nOther than a few Vespoid mosquitos there are no monsters here.\nThere is only one path back out to [Area 7].\n\n";
  Map[1][9].Look = "Almost completely hidden under a wall of rock is a small spring with fish.\nThis place has no creatures.\nThere is only one path back out to [Area 7].\n\n";
  Map[1][10].Look = "A few herbs grow from the walls of the stone path surrounding the center of this Area.\nGenprey raptors seem to have taken a liking to this area and are scattered all around.\nA path of sand on the bottom of this Area leads to [Area 7],\non the walkway a path through the canyon can be seen leading to [Area 4],\nwhile a small hole in the wall might be just big enough to fit through to [Area 11].\n\n";
  Map[1][11].Look = "Many miscellaneous objects are scattered allaround, maybe something of use can be found here.\nOnly Meylynx cats populate this village and they dont seem to want to trade with you.\nThere is only one path back out to [Area 10].\n\n";
  
  Map[1][0].Door = {1, 2};
  Map[1][1].Door = {0, 3, 4};
  Map[1][2].Door = {0, 6, 7};
  Map[1][3].Door = {1, 4};
  Map[1][4].Door = {1, 3, 5, 10};
  Map[1][5].Door = {4, 8};
  Map[1][6].Door = {2};
  Map[1][7].Door = {2, 8, 9, 10};
  Map[1][8].Door = {7};
  Map[1][9].Door = {7};
  Map[1][10].Door = {7, 10, 11};
  Map[1][11].Door = {10};
}

//----------------------------------------------------------------------------------------------------------------Gear
void Gear()
{
  cout << "You have quite an assortment to choose from, you can pick one weapon to get a description of what it does.\nEach weapon has strengths and weaknesses,\nbut all are great for taking out monsters so pick the one that best suits you." << endl;
 
 bool pass = false;
 bool check = false;
 int choice;
 char confirm;
  
  do{
    cout << endl;
    cout << "[0]: Great Sword" << endl;
    cout << "[1]: Long Sword" << endl;
    cout << "[2]: Sword and Sheild" << endl;
    cout << "[3]: Duel Blades" << endl;
    cout << "[4]: Hammer" << endl;
    cout << "[5]: Hunting Horn" << endl;
    cout << "[6]: Lance" << endl;
    cout << "[7]: Gunlance" << endl;
    cout << "[8]: Switchaxe" << endl;
    cout << "[9]: Charge Blade" << endl;
    cout << "[10]: Insect Glave" << endl;
    cout << "[11]: Light Bowgun" << endl;
    cout << "[12]: Heavy Bowgun" << endl;
    cout << "[13]: Bow" << endl;
    
    do{
      cout << ">>Enter:";
      cin >> choice;

      if(cin.fail())
      {
        cin.clear();
        cin.ignore();
        cout << endl << ">>Invalid choice try again<<" << endl << endl;
      }
      else
      {
        cout << endl;
        check = true;
      }
    }while(check == false);
    
    if(choice == 0)
    {
      cout << "The Great Sword is pretty simple, but slow to swing. It has a high damage output, and doesn’t require complex strategy it is almost entirely offense, it’s for those who like dodging around monster attacks and using their knowledge to find the right windows to attack." << endl << endl;
      
      cout << "Would you like to choose this one?\n>>EnterY/N:";
      cin >> confirm;
      
      if(confirm == 'Y' || confirm == 'y')
      {
        PlayerS -> AttackP += 170; 
        PlayerS -> DefenceP += 25; 
        PlayerS -> DodgeP -= 20; 

        pass = true;
      }
    }
    else if(choice == 1)
    {
      cout << "Similarly to the Great Sword, the Long Sword has a high damage output, but swings much faster. Though it has to be charged up to be used to its full effect. Deal damage and unleash a combo to level it up, gaining a damage boost - spend too long not completing the combo, and you’ll lose the boost." << endl << endl;
      
      cout << "Would you like to choose this one?\n>>EnterY/N:";
      cin >> confirm;
      
      if(confirm == 'Y' || confirm == 'y')
      {
        PlayerS -> AttackP += 210; 
        PlayerS -> DefenceP += 0; 
        PlayerS -> DodgeP += 10;
        
        pass = true;
      }
    }
    else if(choice == 2)
    {
      cout << "The most basic weapon is the Sword and Shield. It allows you to block effectively, deal a medium amount of damage, doesn’t leave you open to attack with slow swings, and doesn’t need charging up like the Long Sword. By far the simplest choice." << endl << endl;
      
      cout << "Would you like to choose this one?\n>>EnterY/N:";
      cin >> confirm;
      
      if(confirm == 'Y' || confirm == 'y')
      {
        PlayerS -> AttackP += 210; 
        PlayerS -> DefenceP += 10; 
        PlayerS -> DodgeP += 5;
        
        pass = true;
      }
    }
    else if(choice == 3)
    {
      cout << "Some weapons have elemental damage - the Dual Swords are often the best medium for these. They attack quickly, and so put out a lot of elemental damage on each hit. They are low hitting but attack quickly" << endl << endl;
     
      cout << "Would you like to choose this one?\n>>EnterY/N:";
      cin >> confirm;
      
      if(confirm == 'Y' || confirm == 'y')
      {
        PlayerS -> AttackP += 210; 
        PlayerS -> DefenceP -= 20; 
        PlayerS -> DodgeP += 20;
        
        pass = true;
      }
    }
    else if(choice == 4)
    {
      cout << "[4]: Most weapons deal cutting damage - they can cut tails and body parts off. The Hammer, on the other hand, deals blunt damage, meaning a good attack can destroy armoured limbs or even knock a monster unconscious. It’s slow, but has this high damage output and a useful utility to boot." << endl << endl;
      
      cout << "Would you like to choose this one?\n>>EnterY/N:";
      cin >> confirm;
      
      if(confirm == 'Y' || confirm == 'y')
      {
        PlayerS -> AttackP += 220; 
        PlayerS -> DefenceP += 5; 
        PlayerS -> DodgeP -= 5;
        
        pass = true;
      }
    }
    else if(choice == 5)
    {
      cout << "[5]: For those who like to help allies, the Hunting Horn will offer other hunters bonuses like increased defense if you can play songs with it while dishing out a lot of blunt damage." << endl << endl;
      
      cout << "Would you like to choose this one?\n>>EnterY/N:";
      cin >> confirm;
      
      if(confirm == 'Y' || confirm == 'y')
      {
        PlayerS -> AttackP += 200; 
        PlayerS -> DefenceP += 10; 
        PlayerS -> DodgeP += 0;
        
        pass = true;
      }
    }
    else if(choice == 6)
    {
      cout << "[6]: Lance is a long weapon with huge range plus a large shield for you to defend yourself while attacking. Lances specialize in individual quick jabs and high offensive capability." << endl << endl;
      
      cout << "Would you like to choose this one?\n>>EnterY/N:";
      cin >> confirm;
      
      if(confirm == 'Y' || confirm == 'y')
      {
        PlayerS -> AttackP += 210; 
        PlayerS -> DefenceP += 30; 
        PlayerS -> DodgeP -= 10;
        
        pass = true;
      }
    }
    else if(choice == 7)
    {
      cout << "[7]: Gunlance are similar to Lances as a long weapon with huge range plus a large shield for you to defend yourself while attacking. Gunlances can fire a projectile into a monster from very close range dealing massive damage but then needing to go into cooldown mode." << endl << endl;
      
      cout << "Would you like to choose this one?\n>>EnterY/N:";
      cin >> confirm;
      
      if(confirm == 'Y' || confirm == 'y')
      {
        PlayerS -> AttackP += 220; 
        PlayerS -> DefenceP += 25; 
        PlayerS -> DodgeP -= 10;
        
        pass = true;
      }
    }
    else if(choice == 8)
    {
      cout << "[8]: Switch Axes are good for those who like to put together good combos of high damaging attacks - it lets you swap between an axe and sword form. You’ll get a limited time in sword mode before having to recharge it, but if you want to dance around a monster with a neverending combo, it’s the best choice." << endl << endl;
      
      cout << "Would you like to choose this one?\n>>EnterY/N:";
      cin >> confirm;
      
      if(confirm == 'Y' || confirm == 'y')
      {
        PlayerS -> AttackP += 215; 
        PlayerS -> DefenceP += 0; 
        PlayerS -> DodgeP -= 5;
        
        pass = true;
      }
    }
    else if(choice == 9)
    {
      cout << "[9]: Similarly to the Switch Axe, the Charge Blade also has an axe and sword mode, but is the reverse - it’s a sword by default, with the axe mode being limited by a charge that you must build up. This weapon comes with a shield in sword mode, so it is more defensive than the Switch Axe." << endl << endl;
      
      cout << "Would you like to choose this one?\n>>EnterY/N:";
      cin >> confirm;
      
      if(confirm == 'Y' || confirm == 'y')
      {
        PlayerS -> AttackP += 210; 
        PlayerS -> DefenceP += 5; 
        PlayerS -> DodgeP -= 5;
        
        pass = true;
      }
    }
    else if(choice == 10)
    {
      cout << "[10]: Insect Glaives are incredibly useful for mounting a monster - climbing onto its back to deal huge amounts of damage - using a pole vault attack. With a range and speed similar to the Long Sword, it also comes with a Kinsect, a small insect that can be used to deal damage to a monster from afar." << endl << endl;
      
      cout << "Would you like to choose this one?\n>>EnterY/N:";
      cin >> confirm;
      
      if(confirm == 'Y' || confirm == 'y')
      {
        PlayerS -> AttackP += 200; 
        PlayerS -> DefenceP += 5; 
        PlayerS -> DodgeP += 35;
        
        pass = true;
      }
    }
    else if(choice == 11)
    {
      cout << "[11]: The Light Bowgun allows you to be more mobile, while inflicting damage from afar. They can use a multitude of different ammo type to best suit each confrontation. Though these require a lot of preparation before a hunt, as you’ll have to decide on what ammo to take." << endl << endl;
      
      cout << "Would you like to choose this one?\n>>EnterY/N:";
      cin >> confirm;
      
      if(confirm == 'Y' || confirm == 'y')
      {
        PlayerS -> AttackP += 215; 
        PlayerS -> DefenceP -= 5; 
        PlayerS -> DodgeP += 15;
        
        pass = true;
      }
    }
    else if(choice == 12)
    {
      cout << "[12]: The Heavy Bowgun is much like the Light Bowgunnn counterpart but limits your movement much more while giving you huge damage output in return. These require a lot of preparation before a hunt, as you’ll have to decide on what ammo to take." << endl << endl;
      
      cout << "Would you like to choose this one?\n>>EnterY/N:";
      cin >> confirm;
      
      if(confirm == 'Y' || confirm == 'y')
      {
        PlayerS -> AttackP += 220; 
        PlayerS -> DefenceP += 10; 
        PlayerS -> DodgeP -= 10;
        
        pass = true;
      }
    }
    else if(choice == 13)
    {
      cout << "[13]: Bows are the easier form of ranged weapon. Some bows can fire multiple arrows at once,  while others can pierce through a monster and damage multiple parts of the body. To use this type of weapon effectively, you’ll have to prepair how many coating you will need to bring for a hunt." << endl << endl;
      
      cout << "Would you like to choose this one?\n>>EnterY/N:";
      cin >> confirm;
      
      if(confirm == 'Y' || confirm == 'y')
      {
        PlayerS -> AttackP += 200; 
        PlayerS -> DefenceP -= 5; 
        PlayerS -> DodgeP += 5;
        
        pass = true;
      }
    }
    else
    {
      cout << "Thats not a weapon" << endl;
    }
    
  }while(pass == false);
}

//-----------------------------------------------------------------------------------------------------------------UI
void UI()
{
  char choice;
  bool check = false;
  
  do{
    cout << "=========================" << endl;
    cout << "[C]Combat" << endl;
    cout << "[V]Look around" << endl;
    cout << "[B]Open Bag" << endl;
    cout << "[M]Check Map" << endl;
    cout << "[N]Choose next Area" << endl;
    cout << ">>ENTER:";
  
    cin >> choice;
    cout << endl;
  
    if(choice == 'C' || choice == 'c')
    {
      if(Map[Location][Area].Mon == true)
      {
        Combat();
      }
      else
      {
        cout << "The " << MonsterName << " isnt here to fight" << endl << endl;
      }
      check = true;
    }
    else if(choice == 'V' || choice == 'v')
    {
      cout << Map[Location][Area].Look;
      check = true;
    }
    
    else if(choice == 'B' || choice == 'b')
    {
      InvUI();
      check = true;
    }
    else if(choice == 'M' || choice == 'm')
    {
      MapRoute();
      check = true;
    }
    else if(choice == 'N' || choice == 'n')
    {
      NextArea();
      check = true;
    }
    else
    {
      cout << "Thats not a valid option" << endl << endl;
    }
  }while(check == false);
}

//_________________________________________________________________________________________________________Combat
void Combat()
{
  bool run = false;
  int choice;
  
  do{
    bool check = false;
    
    cout << "----------------------------------------------" << endl;
    cout << ">>Monster: [" << MonsterS -> HealthM << "/1685] HP" << endl;
    cout << ">>Hunter: [" << PlayerS -> HealthP << "/200] HP" << endl << endl;
    
    cout << "[0]: Attack" << endl;
    cout << "[1]: Use Potion" << endl;
    cout << "[2]: Run" << endl;
    
    do{
      cout << ">>Enter:";
      cin >> choice;

      if(cin.fail())
      {
        cin.clear();
        cin.ignore();
        cout << endl << ">>Invalid choice try again<<" << endl << endl;
      }
      else
      {
        check = true;
      }
    }while(check == false);
    
    if(choice == 0)
    {
      int dmg = Calc(PlayerS -> AttackP, MonsterS -> DefenceM, MonsterS -> DodgeM);
      
      MonsterS -> HealthM -= dmg;
      
      cout << "\nMonster -" << dmg << " HP" << endl;
    }
    else if(choice == 1)
    {
      if(Potion > 0)
      {
        if(Potion > 0 && (PlayerS -> HealthP < 200))
        {
          Potion -= 1;
          PlayerS -> HealthP += 25;
          
          if(PlayerS -> HealthP > 200)
          {
            PlayerS -> HealthP = 200;
          }
          
          cout << "\nHunter +25 HP" << endl;
          cout << "[Potion]: " << Potion << endl << endl;
        }
        else if(Potion == 0)
        {
          cout << "\nYou have no more potions" << endl << endl;
        }
      }
    }
    else if(choice == 2)
    {
      Area =  Map[Location][Area].Door[0];
      
      cout << "\nYou start running away to Area " << Area << endl << endl;
      run = true;
    }
    
    if(MonsterS -> HealthM <= 900 && RanAway == false)
    {
      cout << ">>The " << MonsterName << " is wounded and ran to a differnt Area<<" << endl << endl;
      
      PlaceMon();
      Map[Location][Area].Mon = false;
      
      RanAway = true;
      run = true;
    }
    else if(MonsterS -> HealthM <= 0)
    {
      cout << "The " << MonsterName << " is slain\nVictory!\n\n>>Mission Complete<<" << endl;
      run = true;
      Hunt = false;
    }
    else
    {
      if(choice != 2)
      {
        CombatM();
      }
    }
    
    if(PlayerS -> HealthP <= 0)
    {
      cout << "You feinted, Mission Failed" << endl;
      run = true;
      Hunt = false;
    }
  }while(run == false);
}

//________________________________________________________________________________________________Enemy
void CombatM()
{
  int dmg = Calc(MonsterS -> AttackM, PlayerS -> DefenceP, PlayerS -> DodgeP);
  
  PlayerS -> HealthP -= dmg;
  
  cout << "Hunter -" << dmg << " HP" << endl << endl;
}

//___________________________________________________________________________________________________Calc
int Calc(int Atk, int Def, int Ddg)
{
  int damage;
  
  int hit = rand() % 50;
  
  if(hit <= Ddg)
  {
    Atk -= Ddg;
  }
  
  Atk -= (Def / 2);
  
  Atk += (hit / 3);
  
  return damage = Atk;
}

//___________________________________________________________________________________________________Inventory UI
void InvUI()
{
  int choice;
  bool check = false;
  char confirm;
  
  do{
    cout << "[Bag Open]" << endl;
    cout << "[0]Check Health" << endl;
    cout << "[1]Check Inventory" << endl;
    cout << "[2]Gather Resources" << endl;
    cout << "[3]Close Bag" << endl;
    cout << ">>ENTER:";
  
    cin >> choice;
    cout << endl;
  
    if(choice == 0)
    {
      cout << ">>Hunter: [" << PlayerS -> HealthP << "/200] HP" << endl << endl;
    }
    else if(choice == 1)
    {
      cout << "[Potion]: " << Potion << endl << endl;
      
      if(Potion > 0 && (PlayerS -> HealthP < 200))
      {
        cout << "Would you like to use one?\n>>EnterY/N:";
        cin >> confirm;
      
        if(confirm == 'Y' || confirm == 'y')
        {
          cout << endl;
          Potion -= 1;
          PlayerS -> HealthP += 25;
          
          if(PlayerS -> HealthP > 200)
          {
            PlayerS -> HealthP = 200;
          }
          
          cout << "Hunter +25 HP" << endl << endl;
        }
      }
    }
    else if(choice == 2)
    {
      int found = rand() % 10;
      cout << "You search the Area for usable resources..." << endl;
      
      if(found == 0 || found == 1)
      {
        cout << "You found enough resources to make a potion\n[Potion]: +1" << endl << endl;
        Potion ++;
      }
      else 
      {
        cout << "You couldn't find enough usable materials to make a potion" << endl << endl;
      }
    }
    else if(choice == 3)
    {
      check = true;
    }
    else
    {
      cout << "Thats not a valid option" << endl << endl;
    }
  }while(check == false);
}

//_________________________________________________________________________________________________________MapRoute
void MapRoute()
{
  if(Location == 0)
  {
      cout << "** Jurrasic Frontier **" << endl << endl;
      cout << "     6 _______ 5 " << endl;
      cout << "  _/ |\\__    _/ \\_ " << endl;
      cout << " /   |   \\_ 4     \\ " << endl;
      cout << "1 __ 2 _/  /    _ 8 " << endl;
      cout << "|    |     |   /  | " << endl;
      cout << "|    |     \\_ 7   | " << endl;
      cout << "0    \\       /    | " << endl;
      cout << "      \\_ 3 _/    _9 " << endl;
      cout << "         ^     _/ | " << endl;
      cout << "          \\_ 10   | " << endl;
      cout << "              \\_ 11 " << endl;
      cout << endl << endl;
  }
  else if(Location == 1)
  {
    cout << "****** Dunes *******" << endl << endl;
    cout << " 11-10_ " << endl;
    cout << " ____|_\\__ 5 -- 4 _ " << endl;
    cout << "|    \\  \\______/|  \\ " << endl;
    cout << "| 9   \\         /  _| " << endl;
    cout << "|  \\_ 7     3 _/  / " << endl;
    cout << "v   _/ \\_     \\_ 1 " << endl;
    cout << "8 _/     \\_ 2    | " << endl;
    cout << "           / \\__ 0 " << endl;
    cout << "       6 _/ " << endl;
    cout << endl << endl;
  }
}

//_________________________________________________________________________________________________________NextArea
void NextArea()
{
  int path;
  bool check = false;
  bool pass = false;
  
  do{
    do{
      cout << ">>Area#:";
      cin >> path;

      if(cin.fail())
      {
        cin.clear();
        cin.ignore();
        cout << endl << ">>Invalid Area try again<<" << endl << endl;
      }
      else
      {
       pass = true;
      }
    }while(pass == false);
  
    for(int i = 0; i < 5; ++i)
    {
      if(Map[Location][Area].Door[i] == path)
      {
        Area = path;
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout << "[Area " << Area << "]: ";
        cout << Map[Location][Area].Desc;
        CheckMonster();
        check = true;
        break;
      }
    }
    if(check != true)
      {
        cout << "Theres no path to that Area from here " << endl;
      }
  }while(check == false);
}

//----------------------------------------------------------------------------------------------------------------Place Monster
void PlaceMon()
{
  int m = 0;
  string nameslist[] = {"Cephadrome", "Deviljho", "Diablos", "Gendrome", "Glavenus", "Monoblos", "Rathian", "Seregios", "Tigrex", "Malfestio", "Nargacuga", "Rathalos"};
  
  do{
    m = rand() % 11;
  }while(m == 0 || Map[Location][m].Mon == true);
  
  Map[Location][m].Mon = true; // chooses random room in map to spawn monster
  
  MonsterName = nameslist[m];
}

//----------------------------------------------------------------------------------------------------------------CheckMonster
void CheckMonster()
{
  if(Map[Location][Area].Mon == true)
  {
    cout << ">>You found the " << MonsterName << "<<" << endl << endl;
  }
  else
  {
    cout << "The " << MonsterName << " isnt here." << endl << endl;
  }
}