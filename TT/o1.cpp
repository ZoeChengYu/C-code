#include <iostream>
#include <string>
#include <windows.h> // 需要此標頭以使用 SetConsoleOutputCP 和 SetConsoleCP
#include <iomanip>   // 需要此標頭以使用 std::fixed 和 std::setprecision

using namespace std;

struct BikeCost {
    string name;
    double fuel_km_per_liter;
    double fuel_price_per_liter;
    double tire_cost;
    double brake_pad_cost;
    double belt_or_chain_cost;
    double oil_cost_per_1000km;
    double maintenance_without_oil_per_1000km;
    double community_maintenance_without_oil_per_1000km;
    bool is_electric;
    int years;

    // 計算並顯示擁有機車的總成本
    double calculate(double normal_km_per_month, double summer_km_per_month, bool use_contract, bool use_community_shop) const {
        // 計算每年總里程 (9 個正常月份 + 3 個寒暑假月份)
        double total_km_per_year = normal_km_per_month * 9 + summer_km_per_month * 3;
        // 計算指定年數內的總里程
        double total_km = total_km_per_year * years;

        double fuel_cost = 0.0;
        double electricity_cost = 0.0;

        // 根據機車類型計算燃料或電費
        if (!is_electric) {
            // 對於燃油機車：總里程 / 油耗 * 油價
            if (fuel_km_per_liter == 0) { // 避免除以零
                fuel_cost = 0;
            } else {
                fuel_cost = total_km / fuel_km_per_liter * fuel_price_per_liter;
            }
        } else {
            // 對於電動機車：單位價格取決於是否使用合約方案
            // 合約方案單位價格：969 元 / 1600 公里
            // 非合約方案單位價格：1269 元 / 1600 公里
            double unit_price = use_contract ? 969.0 / 1600.0 : 1269.0 / 1600.0;
            electricity_cost = total_km * unit_price;
        }

        // 計算燃油機車的機油成本
        double oil_cost = (total_km / 1000.0) * oil_cost_per_1000km;
        // 根據是否使用社區店決定保養費率
        double maintenance_rate = use_community_shop ? community_maintenance_without_oil_per_1000km : maintenance_without_oil_per_1000km;
        // 計算總保養成本
        double maintenance_cost = (total_km / 1000.0) * maintenance_rate;

        // 計算總體成本
        double total = fuel_cost + electricity_cost + tire_cost + brake_pad_cost + belt_or_chain_cost + oil_cost + maintenance_cost;
        // 計算每公里成本
        double cost_per_km = (total_km == 0) ? 0 : total / total_km; // 避免除以零
        // 計算每月平均成本
        double monthly_average = (years == 0) ? 0 : total / (12.0 * years); // 避免除以零

        // 設定財務數字的輸出精度
        cout << fixed << setprecision(4);

        // 輸出詳細的成本明細
        cout << "======== " << name << (use_community_shop ? "（社區店）" : "（原廠）") << " ========" << endl;
        cout << "總使用年數:       " << years << " 年" << endl;
        cout << "總里程:           " << total_km << " 公里" << endl;
        if (!is_electric) cout << "油費:             " << fuel_cost << " 元" << endl;
        if (is_electric)  cout << "電費:             " << electricity_cost << " 元" << endl;
        cout << "輪胎:             " << tire_cost << " 元" << endl;
        cout << "來令片:           " << brake_pad_cost << " 元" << endl;
        cout << "皮帶/鏈條:        " << belt_or_chain_cost << " 元" << endl;
        cout << "機油:             " << oil_cost << " 元" << endl;
        cout << (use_community_shop ? "社區店" : "原廠") << "定期保養(不含機油): " << maintenance_cost << " 元" << endl;

        // 以粗體顯示總結成本
        cout << "\n\033[1m總費用:           " << total << " 元\033[0m" << endl;
        cout << "\033[1m每公里成本:       " << cost_per_km << " 元\033[0m" << endl;
        cout << "\033[1m每月平均成本:     " << monthly_average << " 元\033[0m\n" << endl;

        return total;
    }
};

int main() {
    // 設定控制台輸出字元集為 UTF-8，以便在 Windows 上正確顯示中文
    SetConsoleOutputCP(CP_UTF8);
    // 設定控制台輸入字元集為 UTF-8
    SetConsoleCP(CP_UTF8);

    double normal_km, summer_km;
    // 提示使用者輸入正常月份的每月里程
    cout << "請輸入每月正常月份里程 (9 個月): ";
    cin >> normal_km;
    // 提示使用者輸入寒暑假月份的每月里程
    cout << "請輸入每月寒暑假月份里程 (3 個月): ";
    cin >> summer_km;

    // 提示使用者輸入迪爵的油耗和油價
    double dio_fuel_km_per_liter, dio_fuel_price;
    cout << "請輸入 迪爵 每公升可行駛公里數（油耗）: ";
    cin >> dio_fuel_km_per_liter;
    cout << "請輸入 迪爵 油價（每公升元）: ";
    cin >> dio_fuel_price;

    // 提示使用者輸入模擬年數
    int input_years;
    cout << "請輸入模擬使用年數: ";
    cin >> input_years;

    // 初始化不同機車模型的 BikeCost 物件
    // 迪爵 (燃油機車)
    BikeCost dio = {"迪爵", dio_fuel_km_per_liter, dio_fuel_price,
        3000, 800, 500, 500, 300, 200, false, input_years};

    // Gogoro Plus 2024 (電動機車)
    BikeCost gogoro_plus_2024 = {"Gogoro Plus 2024", 0, 0,
        4000, 1000, 2000, 0, 300, 150, true, input_years};

    // Gogoro 2 (舊車) (電動機車，模擬使用 1 年)
    BikeCost gogoro2_used = {"Gogoro 2 (舊車)", 0, 0,
        4000, 1000, 3000, 0, 500, 300, true, 1};

    // 計算並顯示每輛機車在不同情境下的成本
    // 迪爵 - 原廠保養
    dio.calculate(normal_km, summer_km, false, false);
    // 迪爵 - 社區店保養
    dio.calculate(normal_km, summer_km, false, true);
    // Gogoro Plus 2024 - 合約方案，原廠保養
    gogoro_plus_2024.calculate(normal_km, summer_km, true, false);
    // Gogoro Plus 2024 - 合約方案，社區店保養
    gogoro_plus_2024.calculate(normal_km, summer_km, true, true);
    // Gogoro 2 (舊車) - 合約方案，原廠保養
    gogoro2_used.calculate(normal_km, summer_km, true, false);
    // Gogoro 2 (舊車) - 合約方案，社區店保養
    gogoro2_used.calculate(normal_km, summer_km, true, true);

    return 0;
}