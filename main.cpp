#include <set>
#include <map>
#include <list>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <Eigen/Dense>
#include <chrono>

using namespace std;
using Eigen::MatrixXd;
std::vector<int> reach_log(MatrixXd n_delta, MatrixXd delta, set<int> Init);
void test_reach_log(int n);
std::set<int> reach(std::map<int, std::set<char>>sigma_f, std::map<std::string, std::set<int>> delta, std::set<int>init);
tuple<map<int, set<char>>, map<string, set<int>>, set<int>> delta2trans(MatrixXd m_n_delta, MatrixXd m_delta, set<int>init);
int main(){

    std::map<int, std::set<char>>sigma_f = {

            {1, {'a'}},

            {2, {'b'}},

            {3, {'c', 'd'}},

            {4, {'e', 'f'}},

            {5, {}}

    };


    std::map<std::string, std::set<int>>delta = {

            {"1,a", {2}},

            {"2,b", {3}},

            {"3,c", {1}},

            {"3,d", {4}},

            {"4,e", {2}},

            {"4,f", {5}}

    };


    std::set<int>init = {1};

    std::map<int, std::set<char>>sigma_f_1 = {

            {1, {'a'}},

            {2, {'a'}},

            {3, {'a'}},

    };


    std::map<std::string, std::set<int>>delta_1 = {

            {"1,a", {2}},

            {"2,a", {3}},

            {"3,c", {3}},

    };


    std::set<int>init_1 = {3};



    std::map<int, std::set<char>>sigma_f_2 = {

            {1, {}},

            {2, {}},

            {3, {}},

            {4, {}},

            {5, {}}

    };


    std::map<std::string, std::set<int>>delta_2 = {

            {"1,a", {2}},

            {"2,b", {3}},

            {"3,c", {1}},

            {"3,d", {4}},

            {"4,e", {2}},

            {"4,f", {5}}

    };


    std::set<int>init_2 = {2};



    std::map<int, std::set<char>>sigma_f_3 = {

            {1, {'a'}},

            {2, {'a'}},

            {3, {'a'}},

            {4, {'a'}}

    };


    std::map<std::string, std::set<int>>delta_3 = {

            {"1,a", {}},

            {"2,a", {}},

            {"3,a", {3}},

            {"4,a", {4}}

    };


    std::set<int>init_3 = {4};



    std::map<int, std::set<char>>sigma_f_4 = {

            {1, {'a'}},

            {2, {'a'}},

            {3, {'a'}},

            {4, {'a'}},

            {5, {'a'}},

            {6, {'a'}},

            {7, {'a'}}

    };


    std::map<std::string, std::set<int>>delta_4 = {

            {"1,a", {2, 3}},

            {"2,a", {3}},

            {"3,a", {4}},

            {"4,a", {5, 7}},

            {"5,a", {6}},

            {"6,a", {7}},

            {"7,a", {7}}

    };


    std::set<int>init_4 = {6};



    std::map<int, std::set<char>>sigma_f_5 = {

            {1, {'a'}},

            {2, {'a'}},

            {3, {'a'}},

            {4, {'a'}},

            {5, {'a'}},

            {6, {'a'}},

            {7, {'a'}},

            {8, {'a'}},

            {9, {'a'}}

    };


    std::map<std::string, std::set<int>>delta_5 = {

            {"1,a", {2, 3}},

            {"2,a", {4, 5, 6}},

            {"3,a", {7, 8, 9}},

            {"4,a", {4}},

            {"5,a", {5}},

            {"6,a", {6}},

            {"7,a", {7}},

            {"8,a", {8}},

            {"9,a", {9}}

    };


    std::set<int>init_5 = {1};



    std::map<int, std::set<char>>sigma_f_6 = {

            {1, {'a'}},

            {2, {'a'}},

            {3, {'a'}},

            {4, {'a'}},

            {5, {'a'}},

            {6, {'a'}},

            {7, {'a'}},

            {8, {'a'}},

            {9, {'a'}},

            {10, {'a'}}

    };


    std::map<std::string, std::set<int>>delta_6 = {

            {"1,a", {2, 3}},

            {"2,a", {3}},

            {"3,a", {4}},

            {"4,a", {5, 7}},

            {"5,a", {6}},

            {"6,a", {7}},

            {"7,a", {2, 8, 9, 10}},

            {"8,a", {}},

            {"9,a", {}},

            {"10,a", {}}

    };

    Eigen::MatrixXd n_delta_1(1, 4);

    Eigen::MatrixXd l_delta_1(1, 4);

    n_delta_1 << 0, 0, 1, 1;

    l_delta_1 << 0, 0, 3, 4;

    Eigen::MatrixXd n_delta_2(1, 9);

    Eigen::MatrixXd l_delta_2(3, 9);

    n_delta_2 << 2, 3, 3, 1, 1, 1, 1, 1, 1;

    l_delta_2 << 2, 4, 7, 4, 5, 6, 7, 8, 9,
                 3, 5, 8, 0, 0, 0, 0, 0, 0,
                 0, 6, 9, 0, 0, 0, 0, 0, 0;

    Eigen::MatrixXd n_delta_3(1, 7);

    Eigen::MatrixXd l_delta_3(2, 7);

    n_delta_3 << 2, 1, 1, 2, 1, 1, 1;

    l_delta_3 << 2, 3, 4, 5, 6, 7, 7,
                 3, 0, 0, 7, 0, 0, 0;

    Eigen::MatrixXd n_delta_4(1, 10);

    Eigen::MatrixXd l_delta_4(4, 10);

    n_delta_4 << 2, 1, 1, 2, 1, 1, 4, 0, 0, 0;

    l_delta_4 << 2, 3, 4, 5, 6, 7, 2, 0, 0, 0,
                 3, 0, 0, 7, 0, 0, 8, 0, 0, 0,
                 0, 0, 0, 0, 0, 0, 9, 0, 0, 0,
                 0, 0, 0, 0, 0, 0, 10, 0, 0, 0;

//    reach_log(n_delta_4, l_delta_4, set<int>{1});

    test_reach_log(20000000);
    return 0;
}

std::vector<int> reach_log(MatrixXd n_delta, MatrixXd delta, set<int> Init) {
    vector<int> x_r_vec;
    set<int> x_r;
    vector<int>::iterator i_xrc;
    set<int>::iterator i_init;
    if (Init.empty()) {
        return x_r_vec;
    }

    if (n_delta.maxCoeff() == 0) {
        for(i_init = Init.begin(); i_init != Init.end(); i_init++){
            x_r_vec.push_back(*i_init);
        }
        return x_r_vec;
    }

//    int n = *Init.rbegin();

    long n = n_delta.cols();

    std::vector<bool> b(n, false);
    std::vector<bool> bf = b;
    std::vector<bool>::iterator i_b;

    int ii = 1;

    for (i_b = b.begin(); i_b != b.end(); i_b++) {

        if (Init.find(ii) != Init.end()) {
            *i_b = true;
        }
        ii++;
    }
    std::vector<bool> bd = b;
    std::vector<int> x(n, 1);
//    std::vector<int>::iterator i_x;

    for (int i_x = 0; i_x < n; i_x++) {

        x[i_x] = i_x + 1;

    }

    std::vector<bool> bd1(n, false);

    std::vector<bool>::iterator i_bd;

    std::vector<bool>::iterator i_bd1;

    int q, ii_bd, ii_n;

    ii_bd = 0;

    while (true) {

        for (bd1 = bf, i_bd = bd.begin(), ii_bd = 0; i_bd != bd.end(); i_bd++, ii_bd++) {

            if (*i_bd == true) {

                q = x[ii_bd];

                for (ii_n = 0; ii_n < n_delta(0, q - 1); ii_n++) {

                    bd1[delta(ii_n, q - 1) - 1] = true;

                }

            }

        }

        for (i_bd = bd.begin(), i_bd1 = bd1.begin(), i_b = b.begin(); i_b != b.end(); i_bd++, i_bd1++, i_b++) {

            *i_bd = *i_bd1 && !*i_b;

            *i_b = *i_b || *i_bd;

        }

        if (bd == bf) { break; }

    }

    x_r = {};
    for(int i = 0; i < n; i++){
        if(b[i] == true){
            x_r_vec.push_back(i + 1);
        }
    }
    set<int>::iterator i_xr;
    cout<<x_r_vec.size()<<"\n";
//    for(i_xrc = x_r_vec.begin(); i_xrc != x_r_vec.end(); i_xrc++){
//        cout<<*i_xrc<<" ";
//    }
//    cout<<"\n";
    return x_r_vec;
}
std::set<int> reach(
        std::map<int, std::set<char>>sigma_f, std::map<std::string, std::set<int>> delta, std::set<int>init){

    int k = 0;

    std::set<int>x_r = init;

    std::list<int>x = {};

    std::vector<std::set<int>>delta_x;

    std::set<int>::iterator it_set;

    std::map<int, std::set<char>>::iterator it_map;

    std::set<char>::iterator it_set_2;

    std::set<char> sigma_f_x;

    std::set<int>temp;

    std::set<int>set_t;

    std::set<int>result;

    std::set<int>::iterator it_r;

    delta_x.push_back(init);


    while(true){

        k++;

        delta_x.push_back({});

        for(it_set = delta_x[k - 1].begin();it_set!= delta_x[k - 1].end(); it_set++){

            sigma_f_x = sigma_f[*it_set];

            for(it_set_2 = sigma_f_x.begin();it_set_2 != sigma_f_x.end();it_set_2++){

//                std::cout<<std::to_string(*it_set) + "," + *it_set_2 + "\n";

                std::string key = std::to_string(*it_set) + "," + *it_set_2;

                set_t = delta[key];

                std::set_union(delta_x[k].begin(), delta_x[k].end(),

                               delta[key].begin(), delta[key].end(),

                               std::inserter(delta_x[k],delta_x[k].end()));

            }}

        std::set_difference(delta_x[k].begin(), delta_x[k].end(),

                            x_r.begin(), x_r.end(), std::inserter(result, result.end()));

        delta_x[k] = result;

        result.clear();

        std::set_union(x_r.begin(),x_r.end(),

                       delta_x[k].begin(), delta_x[k].end(), std::inserter(x_r, x_r.end()));

        if(delta_x[k].empty())

        {

            break;

        }

    }

//    cout<<"Reachable states:\n";
//
//    for(it_r = x_r.begin();it_r != x_r.end(); it_r++){
//
//        cout<<*it_r<<", ";
//
//    }
//
//    cout<<"\n";

    return x_r;

}


void test_reach_log(int n){
    int q = 0;
    std::set<int> Init;
    Eigen::MatrixXd n_delta(1, 7);
    Eigen::MatrixXd delta(4, 7);
    n_delta<< 2, 1, 1, 2, 1, 1, 4;
    delta<< 2, 3, 4, 5, 6, 7, 2,
            3, 0, 0, 7, 0, 0, 8,
            0, 0, 0, 0, 0, 0, 9,
            0, 0, 0, 0, 0, 0, 10;
    Eigen::MatrixXd n_delta_q(1, 10*n);
    Eigen::MatrixXd delta_q(4, 10*n);
    Eigen::MatrixXd I(1, n);
    Eigen::MatrixXd q_add(1, 7);

    n_delta_q = Eigen::MatrixXd::Zero(1, 10*n);
    delta_q = Eigen::MatrixXd::Zero(4, 10*n);
    I = Eigen::MatrixXd::Zero(1, n);

    for(int i = 0; i < n; i++, q = q + 10){
        n_delta_q.block(0, 10*i, 1, 7) = n_delta;
        delta_q.block(0, 10*i, 1, 7) = delta.block(0, 0, 1, 7);
        for(int j = 10*i; j < 10*i + 7; j++){
            delta_q(0, j) += q;
        }
        delta_q(1, 10*i) = delta(1, 0) + q;
        delta_q(1, 10*i + 3) = delta(1, 3) + q;
        delta_q(1, 10*i + 6) = delta(1, 6) + q;
        delta_q(2, 10*i + 6) = delta(2, 6) + q;
        delta_q(3, 10*i + 6) = delta(3, 6) + q;
        I(0, i) = 1 + 10*i;
    }
    std::copy(&I(0, 0), &I(0, n - 1) + 1, std::inserter(Init, Init.end()));
    tuple<map<int, set<char>>, map<string, set<int>>, set<int>> result_tuple;
    map<int, set<char>>sigma_f = get<0>(result_tuple);
    map<string, set<int>>delta_org = get<1>(result_tuple);
    reach(sigma_f, delta_org, Init);
    auto start  = std::chrono::high_resolution_clock::now();
        reach_log(n_delta_q, delta_q, Init);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    cout<<"\n"<<duration.count()<<" ms\n";
}

tuple<map<int, set<char>>, map<string, set<int>>, set<int>> delta2trans(MatrixXd m_n_delta, MatrixXd m_delta, set<int>init){
    map<int, set<char>>sigma_f;
    set<char> event_a = {'a'};
    map<string, set<int>> delta;
    vector<set<int>> terminal;
    set<int> temp_set;
    long n = m_n_delta.cols();
    long m = m_delta.rows();
    MatrixXd temp_col(m_delta.rows(),1);
    for(int i = 1; i <= n; i++){
        sigma_f.insert(make_pair(i, event_a));
    }
    for(int j = 0; j < n; j++, temp_set.clear()){
        std::copy(&m_delta(0, j), &m_delta(m - 1, j) + 1, std::inserter(temp_set, temp_set.end()));
        terminal.push_back(temp_set);
    }
    for(int k = 0; k < n; k++){
        delta.insert(make_pair(to_string(k+1)+","+"a", terminal[k]));
    }
    return tuple<map<int, set<char>>, map<string, set<int>>, set<int>>(sigma_f, delta, init);
}

//void test_n_by_n(MatrixXd)
