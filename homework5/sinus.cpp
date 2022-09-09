#include <functional>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void plot_function(vector<vector<char>> &plot, function<double(double)> f,
                   double res_x, double res_y) {

    int v_len = plot.size();
    int h_len = plot[0].size();
    int v_center = v_len / 2;
    int h_center = h_len / 2;

    double x_left_edge = -(h_center - 1) * res_x;
    double x_right_edge = -x_left_edge;

    double y_top_edge = -(v_center - 1) * res_y;
    double y_bottom_edge = -y_top_edge;

//    cout << x_left_edge << " " << x_right_edge << '\n';
//    cout << y_top_edge << " " << y_bottom_edge;

    double x = x_left_edge;
    for (int i = 0; i < h_len; ++i, x += res_x) {
        double y = f(x);
        if (y_top_edge <= y && y <= y_bottom_edge) {
//            cout << y;
//            cout.flush();
            int approx_y = static_cast<int>(round(y / res_y));
            int point = v_center - approx_y;
            plot[point][i] = '*';
        }
    }
}

void plot_axis(vector<vector<char>> &plot) {
    int v_len = plot.size();
    int h_len = plot[0].size();
    int v_center = v_len / 2;
    int h_center = h_len / 2;

    for (int i = 0; i < v_len; ++i) {
        if (plot[i][h_center] != '*')
            plot[i][h_center] = '|';
        else
            plot[i][h_center] = 'o';
    }

    for (int i = 0; i < h_len; ++i) {
        if (plot[v_center][i] != '*')
            plot[v_center][i] = '-';
        else
            plot[v_center][i] = 'o';
    }
}

void plot_axis_labels(vector<vector<char>> &plot) {
    int v_len = plot.size();
    int h_len = plot[0].size();
    int v_center = v_len / 2;
    int h_center = h_len / 2;

    plot[0][h_center] = '^';
    plot[0][h_center + 1] = 'y';

    plot[v_center][h_len - 2] = '>';
    plot[v_center][h_len - 1] = 'x';

    plot[v_center + 1][h_center - 1] = '0';
}

void print_plot(vector<vector<char>> &plot) {
    cout << endl;
    for (auto row : plot) {
        for (char item : row) {
            cout << item;
        }
        cout << endl;
    }
}
int main() {
    vector<vector<char>> plt(20, vector<char>(120, ' '));
    double res_x = 15.0 / plt[0].size();
    double res_y = 3.0 / plt.size();
    plot_function(
            plt, [](double x){return sin(x);}, res_x, res_y);
    plot_axis(plt);
    plot_axis_labels(plt);
    print_plot(plt);
}