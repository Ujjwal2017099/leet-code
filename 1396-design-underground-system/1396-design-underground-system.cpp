class UndergroundSystem {
    map<int,string> start;
    map<int,int> id_time;
    map<string,int> avg;
    map<string,int> count;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        start[id] = stationName;
        id_time[id] = t;
    }
    
    void checkOut(int id, string stationName, int t) {
        count[start[id]+'-'+stationName]++;
        avg[start[id]+'-'+stationName] += t - id_time[id];
    }
    
    double getAverageTime(string startStation, string endStation) {
        double div = count[startStation +'-'+ endStation];
        
        return avg[startStation +'-'+ endStation]/div;
    }
};
