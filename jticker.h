#ifndef JTICKER_H
#define JTICKER_H
#include <QString>


class JTicker
{
public:
    JTicker();
    double getLast(){   return last_; };
    double getHigh(){   return high_; };
    double getLow(){    return low_; };
    double getVolume(){ return volume_; };
    double getVwap(){   return vwap_; };
    double getMax_bid(){    return max_bid_; };
    double getMin_ask(){    return min_ask_; };
    double getBest_bid(){   return best_bid_; };
    double getBest_ask(){   return best_ask_; };
    double getSpread(){ return spread_; }

    void last(double _last);
    void high(double _higt);
    void low(double _low);
    void volume(double _volume);
    void vwap(double _vwap);
    void max_bid(double _max_bid);
    void min_ask(double _min_ask);
    void best_bid(double _best_bid);
    void best_ask(double _best_ask);
    void bidAndAsk(double _best_bid, double _best_ask);

private:
    double last_;
    double high_;
    double low_;
    double volume_;
    double vwap_;
    double max_bid_;
    double min_ask_;
    double best_bid_;
    double best_ask_;
    double spread_;
};

#endif // JTICKER_H
