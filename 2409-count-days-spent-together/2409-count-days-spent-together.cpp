class Solution {
public:
// After looking at the long code don't get afraid just look at it line by line, section by section & you will understand the intuition used
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        // this will helps us to calculate exact days of the months if two or more months are spent together 
        vector<int> year = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        // calculating alice & bob's arrival, leave month and day
        int aam = stoi(arriveAlice.substr(0,2));
        int aad = stoi(arriveAlice.substr(3,4));
        int alm = stoi(leaveAlice.substr(0,2));
        int ald = stoi(leaveAlice.substr(3,4));

        int bam = stoi(arriveBob.substr(0,2));
        int bad = stoi(arriveBob.substr(3,4));
        int blm = stoi(leaveBob.substr(0,2));
        int bld = stoi(leaveBob.substr(3,4));
        
        // here calculating the effective interval where both of them were present in rome
		// just used some common sense & math to calculate all of these 
        int arriveMonth;
        int arriveDay;
        if(aam > bam){
            arriveMonth = aam;
            arriveDay = aad;
        }
        else if(aam < bam){
            arriveMonth = bam;
            arriveDay = bad;
        }
        else{
            arriveMonth = aam;
            if(aad > bad)arriveDay = aad;
            else arriveDay = bad;
        }
        
        int leaveMonth;
        int leaveDay;
        if(alm < blm){
            leaveMonth = alm;
            leaveDay = ald;
        }
        else if(alm > blm){
            leaveMonth = blm;
            leaveDay = bld;
        }
        else{
            leaveMonth = alm;
            if(ald < bld)leaveDay = ald;
            else leaveDay = bld;
        }

        // checking if one of them left earlier and then another visited rome
        // hence return 0
        if(leaveMonth < arriveMonth)return 0;
        
        if(arriveMonth == leaveMonth){
            if(leaveDay < arriveDay)return 0;
        }
        
        // now after calculating both effective arrival and leave -> month and day
        int days = 0;
        // we will check if months are different means both of them stayed there in 2 or more different months
        if(leaveMonth - arriveMonth > 0){
			// first calculating the days which are spent together in first month
			// subtracting one cause year vector is stored in zero indexed vector
            days += year[arriveMonth-1] - arriveDay+1;
            
			// then calculating all the days of complete months spent together
            for(int i = arriveMonth+1; i < leaveMonth; i++){
                days += year[i-1];
            }
            // then calculating the days of last month spent together, which is just leaveDay
            days += leaveDay;
        }
        // else if the months are same just return -> later day - earlier day + 1
        else days = leaveDay - arriveDay + 1;
        
        return days;
    }
};