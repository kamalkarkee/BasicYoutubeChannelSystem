#include <iostream>
#include <list>
using namespace std;

class YoutubeChannel{
//Encapsulation
private:
string Name;
int CountSubscribers;
list<string> Videotitles;

protected:
string OwnerName; 
int QualityContent;

public:
  //constructor
  YoutubeChannel(string name, string ownername){
    Name=name;
    OwnerName=ownername;
    CountSubscribers=0;
  }
  //functions
  void GetInfo(){
    cout<< "Name: "<< Name <<endl;
    cout<< "OwnerName: " << OwnerName <<endl;
    cout<< "SubscribersCount: "<< CountSubscribers << endl;
    cout<<"Videos: "<<endl;
    for (string videoTitle: Videotitles){
     cout<<videoTitle <<endl;}
    }  
  void Subscribe (){
    CountSubscribers++;
  }
  void Unsubscribe(){
    if (CountSubscribers>0)
      CountSubscribers--;
  }
  void PublishVideo(string videotitle){
    Videotitles.push_back(videotitle);
    }
  void CheckAnalytics(){
    if (QualityContent <4)
      cout<<Name<<" has poor quality content"<<endl;
    else
      cout<<Name<<" has great quality content"<<endl;
  }
};
//Inheritance
class TravelYoutubeChannel:public YoutubeChannel{
  public:
  TravelYoutubeChannel(string nAME, string ownerName):YoutubeChannel(nAME, 
   ownerName){
    
   }
void Vlog(){
  cout<< OwnerName<<" is doing Travel and Food vlog in Nevada\n"<<endl;
  QualityContent++;
}
};
class SportsYoutubeChannel:public YoutubeChannel{
  public:
  SportsYoutubeChannel(string nAME, string ownerName):YoutubeChannel(nAME, 
   ownerName){
    
   }
void Vlog(){
  cout<< OwnerName<<" is presenting soccer news\n"<<endl;
  QualityContent++;
}
};

int main() {
  
  TravelYoutubeChannel TravelChannel("JohnTravelDiary", "John"); 
  SportsYoutubeChannel sportChannel("ABCNews", "Kim");
  TravelChannel.PublishVideo("Hoover Dam, Nevada");
  TravelChannel.Subscribe();
  TravelChannel.GetInfo();
  TravelChannel.Vlog();
  sportChannel.PublishVideo("Soccer news");
  sportChannel.Subscribe();
  sportChannel.Subscribe();
  sportChannel.GetInfo();
  sportChannel.Vlog();
//polymorphism
  YoutubeChannel* yt1= &TravelChannel;
  YoutubeChannel* yt2 = &sportChannel;

  yt1-> CheckAnalytics();
  yt2-> CheckAnalytics();

  return 0;
 }
