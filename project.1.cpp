#include<iostream>
#include<string>
using namespace std;
int main(){
    // Starting stock (change these two values for Test Set 2)
int trucks =5, packs = 120;

// Counters for the final summary
int handled_count = 0;
int deferred_count = 0;

// Loop over the 5 requests
for(int Requist_number=1; Requist_number<=5; Requist_number++){

string  area, damage_level,  route, flood_warning, medical_need, previous_aid;
int families;

cout<<"please Enter your area: \n";
cin>>area;
cout<<"please Enter The damage ('High', 'Mediumme', 'Low'):"<<endl;
cin>>damage_level;
cout<<"please Enter family affected: \n";
cin>>families;

cout<<"pleas Enter route situation (if Damaged enter 'Damaged' \n";
cin>>route;
cout<<"where there a warnaning? (Yes/No) \n";
cin>>flood_warning;
cout<<"do you need any medical need? (yes/No) \n";
cin>>medical_need;
cout<<"have you recived previous aid? (Yes/no) \n";
cin>>previous_aid;

// Need score starts from zero for every request
int total_score = 0;

// Damage level: High = 15, Medium = 10, Low = 5
if(damage_level == "High" ||damage_level =="high"||damage_level =="h"||damage_level =="H"){
    total_score +=15;
} 

else if (damage_level == "mid"||damage_level == "medium"||damage_level == "Medium"||damage_level == "m"||damage_level == "M"){
    total_score +=10;
} 
else if(damage_level == "Low"||damage_level =="low"||damage_level =="l"||damage_level =="L"){
    total_score +=5; 
}
// Invalid input check 
 else { while (damage_level != damage_level)
 {
    cout<<"Please enter valid input\n";
    cin>>damage_level;
 }
 

}
// Families score: families divided by 10 (added to the total below)
int families_score = families/10;

 // Damaged route adds 5
if(route == "damaged"||route ==  "damage" ||route ==  "Damaged"||route == "Damage"||route == "D"||route == "d"){
    total_score+=5;
    
} else {while (route != route )
{
    cout<<"Please enter valid input\n";
    cin>>route; 
}
}


// Flood warning adds 10
if(flood_warning == "yes" || flood_warning == "Yes"){
    total_score+=10;
}
else {while (flood_warning != flood_warning )
{
    cout<<"Please enter valid input\n";
    cin>>flood_warning; 
}
}

// Medical need adds 25 (highest weight, lives are at risk)
if(medical_need == "yes" || medical_need =="Yes"){
    total_score+=25;
} 
else {while (medical_need != medical_need )
{
    cout<<"Please enter valid input\n";
    cin>>medical_need; 
}
}


 // Previous aid subtracts 5
if(previous_aid == "yes" ||previous_aid ==  "Yes"){
    total_score-=5;
}
else {while (previous_aid != previous_aid )
{
    cout<<"Please enter valid input\n";
    cin>>previous_aid; 
}
}     // Print the request information
      cout<< "Requist number < "<<Requist_number<<" > (from [" <<area <<"]  damaged level is [" <<damage_level<<"])\t,        (Families affected[" << families<<"],)\n"
      << "(Route situation [" <<route<<"])\t, (Flood warning [" <<flood_warning<<"])\t, (Medical need [" <<medical_need<<
      "])\t, (Previous Aid [ " <<previous_aid<<"])"<<endl;
      
    // Add the families score to get the final need score
     total_score = total_score +families_score;
     
    // Choose the action from the score (thresholds)
        char Action;
         if(total_score <=75 && total_score >59){
            Action = 'A';  // Full Relief
         }
         else if(total_score <=59 && total_score>40){
           Action = 'B';  // Standard Relief
         }
          else if(total_score <=40 && total_score >20){
         Action = 'C'; // Emergency Kit only
         }
         
         else {
           Action = 'D'; // Defer / Monitor
         }

 /////////  
char wanted_action = Action;   // remember what the score asked for

// Fallback: if stock is not enough, go down one level
if (Action == 'A' && (trucks < 2 || packs < 50)) {
    Action = 'B';
}
if (Action == 'B' && (trucks < 1 || packs < 30)) {
    Action = 'C';
}
if (Action == 'C' && (trucks < 1 || packs < 10)) {
    Action = 'D';
}

// Print the reason if the action changed
if (Action != wanted_action) {
    cout << "Fallback: score wanted [" << wanted_action
         << "] but not enough trucks or packs, gave [" << Action << "]\n";
}////////////////////////////////////////////////////////////////////////////////////////
          // Count the request for the summary
          if(Action == 'D'){
            deferred_count++;
             } else {
            handled_count++;
            }
         cout<<"\t======================================\n\t========================================\n";
          // Trucks and packs needed for the final action
          int truck_needed, packs_needed;

          switch (Action)
          {
         case 'A':
            truck_needed = 2;
            packs_needed = 50;
            break;
        case 'B':
            truck_needed = 1;
            packs_needed = 30;
            break;
         case 'C':
            truck_needed = 1;
            packs_needed = 10;
             break;
            default: truck_needed = 0; //D uses nothing
                     packs_needed = 0;
            break;
          }
         // Subtract the used amount from the stock
          int trucks_used = truck_needed;
          int packs_used = packs_needed;
          trucks -= truck_needed;
          packs -=packs_needed;
            // Print the result of this request
          cout<<"trucks needed ["<<truck_needed<<"]\n";
          cout<<"packs needed ["<<packs_needed<<"]\n";
          cout<<"|total score ["<<total_score<<"])\n";
           cout << "Action: [" << Action << "]\n";

          cout<<"remining trucks ["<<trucks<<"]\n";
          cout<<"remining packs ["<<packs<<"]\n";

cout<<"\t\t=====================\n";
        }       
         // Final summary after all requests
        cout << "===== Summary =====\n";
    cout << "Handled:  " << handled_count << "\n";
    cout << "Deferred: " << deferred_count << "\n";

             

    return 0;
 
    }

//     # Relief Supply Distribution System
// CS 110 Assignment 1 - Aiman Hesam, Abdulqawi Alolofi
// C++ program: scores relief requests, picks action A/B/C/D, updates trucks and packs.
// Files: project.1.cpp (code), test_set_1.txt and test_set_2.txt (outputs)
// Test Set 1: int trucks =5, packs = 120;   Test Set 2: int trucks =3, packs = 60;
