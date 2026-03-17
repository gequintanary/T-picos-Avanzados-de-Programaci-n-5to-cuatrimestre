#include <iostream>
#include <filesystem>
#include <string>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <cstdio>
#include <memory>
#include <vector>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <regex>
#include <ctime>
#include <windows.h>
#include <shellapi.h>

namespace fs = std::filesystem;

// Paleta de Colores Re-Animator
#define REAGENT_GREEN  "\033[38;5;82m"  
#define SURGICAL_WHITE "\033[38;5;15m"  
#define BLOOD_RED      "\033[38;5;196m" 
#define AMBIENT_DIM    "\033[2m"        
#define GOLD_TAG       "\033[38;5;220m"
#define RESET          "\033[0m"

struct MovieEntry {
    std::string title;
    std::string posterPath;
    std::string thumbnailPath;
    std::string folderPath;
    double sizeGB;
    std::string fingerprint;
};

struct LabSettings {
    bool stealthMode = false;
    std::string colorTheme = REAGENT_GREEN;
} settings;

struct LabStats {
    int total = 0, saved = 0, surgery = 0, dead = 0;
    double totalGB = 0.0;
    std::vector<MovieEntry> gallery;
    void reset() { total = saved = surgery = dead = 0; totalGB = 0.0; gallery.clear(); }
} stats;

// --- AUDIO & SENTINEL MODULES ---
void playHeartbeat(bool ok) {
    if (settings.stealthMode) return;
    if (ok) { Beep(1200, 150); Sleep(50); Beep(1200, 150); }
    else { Beep(300, 800); }
}

void sendNotification(const std::string& title, const std::string& msg) {
    std::string cmd = "powershell -Command \"Add-Type -AssemblyName System.Windows.Forms; $n = New-Object System.Windows.Forms.NotifyIcon; $n.Icon = [System.Drawing.SystemIcons]::Information; $n.Visible = $true; $n.ShowBalloonTip(5000, '" + title + "', '" + msg + "', [System.Windows.Forms.ToolTipIcon]::Info);\"";
    std::system(cmd.c_str());
}

// --- MÓDULO DE LIMPIEZA DE LABORATORIO (NUEVO) ---
void cleanupLaboratory() {
    std::vector<std::string> targetFiles = { "autopsy_report.log", "error_log" };
    for (const auto& file : targetFiles) {
        if (fs::exists(file)) {
            fs::remove(file);
        }
    }
}

// --- HARDWARE DIAGNOSTICS & VITAL CAPACITY ---
void showVitalCapacity(const fs::path& path) {
    fs::space_info si = fs::space(path.root_path());
    double freeGB = static_cast<double>(si.available) / (1024 * 1024 * 1024);
    std::cout << AMBIENT_DIM << "[CAPACITY]: " << std::fixed << std::setprecision(2) << freeGB << " GB available on ROG Arion (F:)" << RESET << std::endl;
}

bool checkDriveHealth() {
    std::cout << SURGICAL_WHITE << "[SYSTEM]: Bio-Metric Scan (PowerShell Fix)..." << RESET << std::endl;
    std::string cmd = "powershell -Command \"Get-WmiObject -Query 'SELECT Status FROM Win32_DiskDrive' | Select-Object -ExpandProperty Status\"";
    std::unique_ptr<FILE, decltype(&_pclose)> pipe(_popen(cmd.c_str(), "r"), _pclose);
    char buf[128]; std::string res;
    while (fgets(buf, 128, pipe.get())) res += buf;
    bool ok = (res.find("OK") != std::string::npos);
    playHeartbeat(ok);
    return ok;
}

void runVascularTest(const fs::path& drivePath) {
    std::cout << GOLD_TAG << "[STRESS TEST]: Injecting 1GB Stress Flow..." << RESET << std::endl;
    fs::path testFile = drivePath / "vascular_test.tmp";
    std::vector<char> data(1024 * 1024, 'X');
    auto start = std::chrono::high_resolution_clock::now();
    std::ofstream out(testFile, std::ios::binary);
    for (int i = 0; i < 1024; ++i) out.write(data.data(), data.size());
    out.close();
    auto end = std::chrono::high_resolution_clock::now();
    double elapsed = std::chrono::duration<double>(end - start).count();
    std::cout << REAGENT_GREEN << "    >> Flow Rate: " << (1024.0 / elapsed) << " MB/s" << RESET << std::endl;
    fs::remove(testFile);
    playHeartbeat(true);
}

// --- CLINICAL FILENAME CLEANUP & FINGERPRINTING ---
std::string cleanName(std::string name) {
    std::vector<std::string> p = { "\\d{3,4}p", "AMZN", "WEB-DL", "DDP5\\.1", "H\\.264", "x264", "x265", "HEVC", "BluRay", "UHD", "\\.", "-" };
    for (const auto& pat : p) name = std::regex_replace(name, std::regex(pat, std::regex_constants::icase), " ");
    name = std::regex_replace(name, std::regex(" +"), " ");
    return name.substr(name.find_first_not_of(" "), name.find_last_not_of(" ") + 1);
}

std::string getFingerprint(const fs::path& path) {
    std::string cmd = "powershell -Command \"(Get-FileHash '" + path.string() + "' -Algorithm SHA256).Hash\"";
    std::unique_ptr<FILE, decltype(&_pclose)> pipe(_popen(cmd.c_str(), "r"), _pclose);
    char buf[128]; std::string res;
    if (fgets(buf, 128, pipe.get())) res = buf;
    res.erase(std::remove(res.begin(), res.end(), '\n'), res.end());
    return res.substr(0, 16) + "...";
}

// --- ANALYSIS & SURGERY ---
bool attemptSurgery(const fs::path& path, const fs::path& surgery) {
    fs::path fixPath = surgery / ("FIXED_" + path.filename().string());
    std::string cmd = "ffmpeg -v error -i \"" + path.string() + "\" -c copy -map 0 \"" + fixPath.string() + "\" -y";
    if (std::system(cmd.c_str()) == 0) {
        fs::copy(fixPath, path, fs::copy_options::overwrite_existing);
        fs::remove(fixPath);
        return true;
    }
    return false;
}

void processSubject(const fs::path& path, const fs::path& morgue, const fs::path& surgery) {
    std::string name = cleanName(path.stem().string());
    double size = static_cast<double>(fs::file_size(path)) / (1024.0 * 1024.0 * 1024.0);
    std::cout << SURGICAL_WHITE << "\n[EXAMINING]: " << RESET << name << " (" << std::fixed << std::setprecision(2) << size << " GB)" << std::endl;

    std::string durCmd = "ffprobe -v error -show_entries format=duration -of default=noprint_wrappers=1:nokey=1 \"" + path.string() + "\"";
    std::unique_ptr<FILE, decltype(&_pclose)> pDur(_popen(durCmd.c_str(), "r"), _pclose);
    char b[128]; fgets(b, 128, pDur.get());
    double totalTime = std::stod(b);

    std::string cmd = "ffmpeg -v error -progress pipe:1 -i \"" + path.string() + "\" -f null - 2> autopsy_report.log";
    std::unique_ptr<FILE, decltype(&_pclose)> pipe(_popen(cmd.c_str(), "r"), _pclose);
    while (fgets(b, 128, pipe.get())) {
        if (std::string(b).find("out_time_us=") != std::string::npos) {
            double cur = std::stoll(std::string(b).substr(12)) / 1000000.0;
            int pct = (cur / totalTime) * 100;
            if (pct > 100) pct = 100;
            std::cout << "\r" << settings.colorTheme << "    [INJECTING REAGENT]: [" << std::string(pct / 5, '|') << std::string(20 - (pct / 5), '.') << "] " << pct << "%" << RESET << std::flush;
        }
    }

    if (_pclose(pipe.release()) == 0) {
        std::cout << REAGENT_GREEN << "\n    >> SUCCESS: Subject is stable." << RESET << std::endl;
        playHeartbeat(true);
        stats.gallery.push_back({ name, "", "", path.parent_path().string(), size, getFingerprint(path) });
        stats.saved++; stats.totalGB += size;
    }
    else {
        if (attemptSurgery(path, surgery)) { stats.saved++; stats.surgery++; stats.totalGB += size; }
        else { stats.dead++; fs::rename(path, morgue / path.filename()); playHeartbeat(false); }
    }
}

// --- CATALOG GENERATION ---
void generateHTML(const fs::path& base) {
    std::ofstream html(base / "reanimation_gallery.html");
    html << "<html><head><style>body{background:#050505;color:#52ff39;font-family:monospace;padding:30px;}"
        << ".grid{display:grid;grid-template-columns:repeat(auto-fill,minmax(250px,1fr));gap:25px;}"
        << ".card{border:1px solid #32cd32;background:#0a0a0a;text-align:center;padding:15px;transition:0.3s;}"
        << ".card:hover{transform:scale(1.05);box-shadow:0 0 20px #32cd32;}</style></head><body>"
        << "<h1>H. WEST CATALOG - TOTAL: " << std::fixed << std::setprecision(2) << stats.totalGB << " GB</h1><div class='grid'>";
    for (const auto& m : stats.gallery) {
        html << "<div class='card'><h3>" << m.title << "</h3><p>" << m.sizeGB << " GB</p><p style='font-size:0.7em'>ID: " << m.fingerprint << "</p>"
            << "<a href='file:///" << m.folderPath << "' style='color:#32cd32'>OPEN FOLDER</a></div>";
    }
    html << "</div></body></html>";
}

int main() {
    fs::path moviePath("F:/Movies/Horror_Slasher");
    int choice;

    do {
        system("cls");
        std::cout << settings.colorTheme << R"(
    ##########################################################
    #                                                        #
    #   H. WEST & ASSOC. - DATA RE-ANIMATION PROTOCOL v17.0  #
    #   "I must have fresh files... fresh specimens!"        #
    #                                                        #
    ##########################################################
        )" << RESET << std::endl;

        if (fs::exists(moviePath)) showVitalCapacity(moviePath);
        else { std::cout << BLOOD_RED << "ROG ARION DISCONNECTED" << RESET << std::endl; }

        std::cout << "\n1. Health Scan  2. Stress Test  3. Re-Animation  4. Toggle Stealth  5. Gallery  6. Exit\nSELECT: ";
        if (!(std::cin >> choice)) { std::cin.clear(); std::cin.ignore(100, '\n'); continue; }

        if (choice == 4) { settings.stealthMode = !settings.stealthMode; settings.colorTheme = settings.stealthMode ? BLOOD_RED : REAGENT_GREEN; continue; }

        switch (choice) {
        case 1: checkDriveHealth(); std::system("pause"); break;
        case 2: runVascularTest(moviePath.parent_path()); std::system("pause"); break;
        case 3: {
            stats.reset();
            std::cout << "Search Keyword (Empty for all): "; std::string s; std::getline(std::cin >> std::ws, s);
            std::transform(s.begin(), s.end(), s.begin(), ::tolower);
            for (const auto& item : fs::recursive_directory_iterator(moviePath)) {
                if (item.is_regular_file() && (item.path().extension() == ".mkv" || item.path().extension() == ".mp4")) {
                    std::string n = item.path().filename().string();
                    std::transform(n.begin(), n.end(), n.begin(), ::tolower);
                    if (s.empty() || n.find(s) != std::string::npos) processSubject(item.path(), moviePath.parent_path() / "Morgue", moviePath.parent_path() / "Surgery");
                }
            }
            generateHTML(moviePath.parent_path());
            sendNotification("Lab Update", "Autopsy batch complete.");
            std::system("pause"); break;
        }
        case 5: ShellExecuteA(NULL, "open", (moviePath.parent_path() / "reanimation_gallery.html").string().c_str(), NULL, NULL, SW_SHOWNORMAL); break;
        case 6:
            cleanupLaboratory(); // Auto-limpieza antes de salir
            std::cout << REAGENT_GREEN << "Laboratory cleaned. Closing Sentinel..." << RESET << std::endl;
            Sleep(1000);
            break;
        }
    } while (choice != 6);
    return 0;
}