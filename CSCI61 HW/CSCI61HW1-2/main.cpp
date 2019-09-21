#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <utility>
#include <queue>

//typedef pair<double,double> customer;
double exp_rand(double rate);
double average_waiting_time(
        double arrival_rate, double service_rate, std::size_t N);

using namespace std;

int main(){
    srand(time(0));
    const std::size_t N(1000000);

    cout << average_waiting_time(1.0, 5.0, N) << endl;
    cout << average_waiting_time(1.0, 3.0, N) << endl;
    cout << average_waiting_time(1.0, 2.0, N) << endl;
    cout << average_waiting_time(1.0, 1.5, N) << endl;
    cout << average_waiting_time(1.0, 1.1, N) << endl;
    cout << average_waiting_time(1.0, 1.05, N) << endl;
    cout << average_waiting_time(1.0, 1.025, N) << endl;

    return 0;

}
double average_waiting_time(
        double arrival_rate, double service_rate, std::size_t N){
    std::queue<std::pair<double,double>> student;
    double atime = 0.0;
    for(size_t i = 0; i < N; ++i){
        atime += exp_rand(arrival_rate);
        double btime = exp_rand(service_rate);
        student.push(std::pair<double,double>(atime, btime));
    }
    double total_wait = 0.0;
    //subtract the arrival time of next person
    //from the time you're done to calc wait time
    //gives the time the first person ends
    double time_done = 0.0;
    while(!student.empty()){
        //first person has no wait
        double arrival_time(student.front().first);
        double service_time(student.front().second);
        double personal_wait = time_done - arrival_time;
        if(personal_wait < 0) personal_wait = 0;
        //subtract new arrival time from time_done
        total_wait += personal_wait;
        time_done = arrival_time + personal_wait + service_time;
        student.pop();
    }
    return total_wait/N;
}

double exp_rand(double rate){
    double u;
    do
    {
        u = rand()/static_cast<double>(RAND_MAX);
    } while (u == 0.0 || u == 1.0);

    return -log(u)/rate;
}

