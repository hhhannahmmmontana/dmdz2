#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <clocale>
#include <algorithm>
#include <queue>

struct Path {
    std::string name;
    unsigned long weight;
    Path() = default;
    Path(const std::string& name, int weight) {
        this->name = name;
        this->weight = weight;
    }
    bool operator<(const Path& other) const {
        return (this->name < other.name);
    }
};

struct Edge {
    std::string a;
    std::string b;
    unsigned long weight;
    Edge() = default;
    Edge(const std::string& a, const std::string& b, unsigned long weight) {
        this->a = a;
        this->b = b;
        this->weight = weight;
    }
    bool operator<(const Edge& other) const {
        return (this->weight < other.weight || (this->weight == other.weight && (this->a < other.a || (this->a == other.a && this->b < other.b))));
    }
};

std::map<std::string, std::set<Path>> GetGraph() {
    std::map<std::string, std::set<Path>> graph;
    graph["Бельгия"].emplace("Нидерланды", 209);
    graph["Бельгия"].emplace("Франция", 264);
    graph["Бельгия"].emplace("Люксембург", 212);
    graph["Бельгия"].emplace("Германия", 754);

    graph["Нидерланды"].emplace("Бельгия", 209);
    graph["Нидерланды"].emplace("Германия", 656);

    graph["Исландия"] = std::set<Path>();

    graph["Люксембург"].emplace("Германия", 761);
    graph["Люксембург"].emplace("Бельгия", 212);
    graph["Люксембург"].emplace("Франция", 287);

    graph["Германия"].emplace("Нидерланды", 656);
    graph["Германия"].emplace("Бельгия", 754);
    graph["Германия"].emplace("Люксембург", 761);
    graph["Германия"].emplace("Франция", 1045);
    graph["Германия"].emplace("Швейцария", 444);
    graph["Германия"].emplace("Австрия", 538);
    graph["Германия"].emplace("Чехия", 635);
    graph["Германия"].emplace("Польша", 670);
    graph["Германия"].emplace("Дания", 355);

    graph["Швеция"].emplace("Норвегия", 523);
    graph["Швеция"].emplace("Финляндия", 479);
    graph["Швеция"].emplace("Дания", 653);

    graph["Норвегия"].emplace("Россия", 1643);
    graph["Норвегия"].emplace("Финляндия", 986);
    graph["Норвегия"].emplace("Швеция", 523);

    graph["Россия"].emplace("Норвегия", 1643);
    graph["Россия"].emplace("Финляндия", 892);
    graph["Россия"].emplace("Польша", 1151);
    graph["Россия"].emplace("Литва", 791);
    graph["Россия"].emplace("Латвия", 842);
    graph["Россия"].emplace("Эстония", 868);
    graph["Россия"].emplace("Беларусь", 675);
    graph["Россия"].emplace("Украина", 755);

    graph["Великобритания"].emplace("Ирландия", 461);

    graph["Швейцария"].emplace("Германия", 444);
    graph["Швейцария"].emplace("Франция", 487);
    graph["Швейцария"].emplace("Италия", 685);
    graph["Швейцария"].emplace("Лихтенштейн", 568);
    graph["Швейцария"].emplace("Австрия", 591);

    graph["Дания"].emplace("Швеция", 653);
    graph["Дания"].emplace("Германия", 355);

    graph["Финляндия"].emplace("Россия", 892);
    graph["Финляндия"].emplace("Норвегия", 986);
    graph["Финляндия"].emplace("Швеция", 479);

    graph["Эстония"].emplace("Россия", 868);
    graph["Эстония"].emplace("Латвия", 279);

    graph["Ирландия"].emplace("Великобритания", 461);

    graph["Джерси"] = std::set<Path>();

    graph["Лихтенштейн"].emplace("Швейцария", 568);
    graph["Лихтенштейн"].emplace("Австрия", 351);

    graph["Чехия"].emplace("Германия", 635);
    graph["Чехия"].emplace("Польша", 571);
    graph["Чехия"].emplace("Словакия", 290);
    graph["Чехия"].emplace("Австрия", 251);

    graph["Польша"].emplace("Германия", 670);
    graph["Польша"].emplace("Россия", 1151);
    graph["Польша"].emplace("Чехия", 571);
    graph["Польша"].emplace("Словакия", 532);
    graph["Польша"].emplace("Литва", 393);
    graph["Польша"].emplace("Украина", 689);
    graph["Польша"].emplace("Беларусь", 475);

    graph["Литва"].emplace("Россия", 791);
    graph["Литва"].emplace("Латвия", 261);
    graph["Литва"].emplace("Беларусь", 172);
    graph["Литва"].emplace("Польша", 393);

    graph["Латвия"].emplace("Россия", 842);
    graph["Латвия"].emplace("Эстония", 279);
    graph["Латвия"].emplace("Беларусь", 402);
    graph["Латвия"].emplace("Литва", 261);

    graph["Беларусь"].emplace("Россия", 675);
    graph["Беларусь"].emplace("Латвия", 402);
    graph["Беларусь"].emplace("Литва", 172);
    graph["Беларусь"].emplace("Польша", 475);
    graph["Беларусь"].emplace("Украина", 433);

    graph["Франция"].emplace("Бельгия", 264);
    graph["Франция"].emplace("Люксембург", 287);
    graph["Франция"].emplace("Германия", 1045);
    graph["Франция"].emplace("Швейцария", 487);
    graph["Франция"].emplace("Италия", 1105);
    graph["Франция"].emplace("Андорра", 709);
    graph["Франция"].emplace("Испания", 1052);
    graph["Франция"].emplace("Монако", 458);

    graph["Италия"].emplace("Швейцария", 685);
    graph["Италия"].emplace("Австрия", 763);
    graph["Италия"].emplace("Словения", 489);
    graph["Италия"].emplace("Сан-Марино", 227);
    graph["Италия"].emplace("Ватикан", 4);
    graph["Италия"].emplace("Франция", 1105);

    graph["Австрия"].emplace("Италия", 763);
    graph["Австрия"].emplace("Лихтенштейн", 351);
    graph["Австрия"].emplace("Швейцария", 591);
    graph["Австрия"].emplace("Германия", 538);
    graph["Австрия"].emplace("Чехия", 251);
    graph["Австрия"].emplace("Словакия", 55);
    graph["Австрия"].emplace("Венгрия", 215);
    graph["Австрия"].emplace("Словения", 276);

    graph["Словакия"].emplace("Австрия", 55);
    graph["Словакия"].emplace("Чехия", 290);
    graph["Словакия"].emplace("Польша", 532);
    graph["Словакия"].emplace("Украина", 1004);
    graph["Словакия"].emplace("Венгрия", 162);

    graph["Украина"].emplace("Словакия", 1004);
    graph["Украина"].emplace("Польша", 689);
    graph["Украина"].emplace("Беларусь", 433);
    graph["Украина"].emplace("Россия", 755);
    graph["Украина"].emplace("Приднестровье", 407);
    graph["Украина"].emplace("Молдавия", 400);
    graph["Украина"].emplace("Румыния", 747);
    graph["Украина"].emplace("Венгрия", 898);

    graph["Монако"].emplace("Франция", 458);

    graph["Испания"].emplace("Франция", 1052);
    graph["Испания"].emplace("Андорра", 493);
    graph["Испания"].emplace("Португалия", 503);

    graph["Андорра"].emplace("Франция", 709);
    graph["Андорра"].emplace("Испания", 493);

    graph["Словения"].emplace("Италия", 489);
    graph["Словения"].emplace("Австрия", 276);
    graph["Словения"].emplace("Венгрия", 489);
    graph["Словения"].emplace("Хорватия", 516);

    graph["Португалия"].emplace("Испания", 503);

    graph["Ватикан"].emplace("Италия", 4);
    graph["Сан-Марино"].emplace("Италия", 227);

    graph["Хорватия"].emplace("Словения", 516);
    graph["Хорватия"].emplace("Венгрия", 300);
    graph["Хорватия"].emplace("Сербия", 367);
    graph["Хорватия"].emplace("Босния и Герцеговина", 405);
    graph["Хорватия"].emplace("Черногория", 284);

    graph["Венгрия"].emplace("Хорватия", 300);
    graph["Венгрия"].emplace("Словения", 489);
    graph["Венгрия"].emplace("Австрия", 215);
    graph["Венгрия"].emplace("Словакия", 162);
    graph["Венгрия"].emplace("Украина", 898);
    graph["Венгрия"].emplace("Румыния", 642);
    graph["Венгрия"].emplace("Сербия", 316);

    graph["Румыния"].emplace("Венгрия", 642);
    graph["Румыния"].emplace("Украина", 747);
    graph["Румыния"].emplace("Молдавия", 358);
    graph["Румыния"].emplace("Болгария", 295);
    graph["Румыния"].emplace("Сербия", 448);

    graph["Молдавия"].emplace("Румыния", 358);
    graph["Молдавия"].emplace("Украина", 400);
    graph["Молдавия"].emplace("Приднестровье", 62);

    graph["Приднестровье"].emplace("Молдавия", 62);
    graph["Приднестровье"].emplace("Украина", 407);

    graph["Мальта"] = std::set<Path>();

    graph["Босния и Герцеговина"].emplace("Хорватия", 405);
    graph["Босния и Герцеговина"].emplace("Сербия", 198);
    graph["Босния и Герцеговина"].emplace("Черногория", 179);

    graph["Сербия"].emplace("Босния и Герцеговина", 198);
    graph["Сербия"].emplace("Хорватия", 367);
    graph["Сербия"].emplace("Венгрия", 316);
    graph["Сербия"].emplace("Румыния", 448);
    graph["Сербия"].emplace("Болгария", 329);
    graph["Сербия"].emplace("Македония", 323);
    graph["Сербия"].emplace("Косово", 245);
    graph["Сербия"].emplace("Черногория", 300);

    graph["Болгария"].emplace("Сербия", 329);
    graph["Болгария"].emplace("Румыния", 295);
    graph["Болгария"].emplace("Турция", 503);
    graph["Болгария"].emplace("Греция", 526);
    graph["Болгария"].emplace("Македония", 173);

    graph["Турция"].emplace("Болгария", 503);
    graph["Турция"].emplace("Греция", 561);

    graph["Черногория"].emplace("Хорватия", 284);
    graph["Черногория"].emplace("Босния и Герцеговина", 179);
    graph["Черногория"].emplace("Сербия", 300);
    graph["Черногория"].emplace("Косово", 157);
    graph["Черногория"].emplace("Албания", 170);

    graph["Косово"].emplace("Черногория", 157);
    graph["Косово"].emplace("Сербия", 245);
    graph["Косово"].emplace("Македония", 77);
    graph["Косово"].emplace("Албания", 251);

    graph["Македония"].emplace("Косово", 77);
    graph["Македония"].emplace("Сербия", 323);
    graph["Македония"].emplace("Болгария", 173);
    graph["Македония"].emplace("Греция", 488);
    graph["Македония"].emplace("Албания", 153);

    graph["Албания"].emplace("Черногория", 170);
    graph["Албания"].emplace("Косово", 251);
    graph["Албания"].emplace("Македония", 153);
    graph["Албания"].emplace("Греция", 501);

    graph["Греция"].emplace("Албания", 501);
    graph["Греция"].emplace("Македония", 488);
    graph["Греция"].emplace("Болгария", 526);
    graph["Греция"].emplace("Турция", 561);

    return graph;
}

void Test(std::map<std::string, std::set<Path>>& graph) {
    for (const auto& i : graph) {
        for (const auto& j : i.second) {
            bool found = false;
            for (const auto& c : graph[j.name]) {
                if (c.name == i.first && c.weight == j.weight) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                std::cerr << "ERROR IN " << i.first;
                exit(EXIT_FAILURE);
            }
        }
    }
}

void DFS(const std::string& node, const std::string& prev, std::map<std::string, std::set<Path>>& graph, std::map<std::string, bool>& visited, std::map<std::string, std::set<Path>>& component) {
    visited[node] = true;
    component.emplace(node, graph[node]);
    for (const auto& i : graph[node]) {
        if (!visited[i.name] && node != prev) {
            DFS(i.name, node, graph, visited, component);
        }
    }
}

std::vector<std::map<std::string, std::set<Path>>> Components(std::map<std::string, std::set<Path>>& graph) {
    std::vector<std::map<std::string, std::set<Path>>> components;
    std::map<std::string, bool> visited;
    for (const auto& i : graph) {
        visited[i.first] = false;
    }
    for (const auto& i : graph) {
        if (!visited[i.first]) {
            components.emplace_back();
            DFS(i.first, "", graph, visited, components.back());
        }
    }
    return components;
}

std::map<std::string, std::set<Path>> MaxComponent(std::map<std::string, std::set<Path>>& graph) {
    auto components = Components(graph);
    int max_id = 0;
    for (int i = 1; i < components.size(); ++i) {
        max_id = (components[max_id].size() > components[i].size()) ? max_id : i;
    }
    return components[max_id];
}

std::map<std::string, std::map<std::string, unsigned long>> MakeWays(const std::map<std::string, std::set<Path>>& graph) {
    std::map<std::string, std::map<std::string, unsigned long>> ways;
    for (const auto& i : graph) {
        for (const auto& j : graph) {
            ways[i.first][j.first] = (i.first == j.first) ? 0 : INT_MAX;
        }
    }
    for (const auto& i : graph) {
        for (const auto& j : i.second) {
            ways[i.first][j.name] = 1;
        }
    }
    return ways;
}

std::map<std::string, std::map<std::string, unsigned long>> FloydWarshall(const std::map<std::string, std::set<Path>>& graph) {
    auto ways = MakeWays(graph);
    for (const auto& i : graph) {
        for (const auto& u : graph) {
            for (const auto& v : graph) {
                if (ways[u.first][i.first] == INT_MAX || ways[i.first][v.first] == INT_MAX) {
                    continue;
                } else {
                    if (ways[u.first][i.first] + ways[i.first][v.first] < ways[u.first][v.first]) {
                        ways[u.first][v.first] = ways[u.first][i.first] + ways[i.first][v.first];
                        ways[v.first][u.first] = ways[u.first][v.first];
                    }
                }
            }
        }
    }
    return ways;
}

unsigned long FindMin(std::map<std::string, std::map<std::string, unsigned long>>& ways) {
    unsigned long min = INT_MAX;
    for (const auto& i : ways) {
        unsigned long temp_min = 0;
        for (const auto& j : i.second) {
            if (j.second != INT_MAX && i.first != j.first) {
                temp_min = (temp_min > j.second) ? temp_min : j.second;
            }
        }
        min = (min < temp_min) ? min : temp_min;
    }
    return min;
}

unsigned long FindMax(std::map<std::string, std::map<std::string, unsigned long>>& ways) {
    unsigned long max = 0;
    for (const auto& i : ways) {
        for (const auto& j : i.second) {
            if (j.second != INT_MAX && i.first != j.first) {
                max = (max > j.second) ? max : j.second;
            }
        }
    }
    return max;
}

std::set<std::string> FindCenter(std::map<std::string, std::map<std::string, unsigned long>>& ways, std::map<std::string, std::set<Path>>& graph, unsigned long min) {
    std::map<std::string, unsigned long> max_paths;
    for (const auto& i : graph) {
        max_paths[i.first] = INT_MAX;
    }
    std::set<std::string> centers;
    for (const auto& i : ways) {
        unsigned long temp_min = 0;
        for (const auto& j : i.second) {
            if (j.second != INT_MAX && i.first != j.first) {
                temp_min = (temp_min > j.second) ? temp_min : j.second;
            }
        }
        if (temp_min == min) {
            centers.insert(i.first);
        }
    }
    return centers;
}

void Second(std::map<std::string, std::set<Path>>& graph) {
    auto new_graph = MaxComponent(graph);
    const unsigned long kComponentAmount = 1;
    unsigned long vertex = new_graph.size(), edges = 0, min_deg = UINT_MAX, max_deg = 0;
    for (const auto& i : new_graph) {
        edges += i.second.size();
        min_deg = (min_deg < i.second.size()) ? min_deg : i.second.size();
        max_deg = (max_deg > i.second.size()) ? max_deg : i.second.size();
    }
    edges = edges / 2;
    auto ways = FloydWarshall(new_graph);
    unsigned long R = FindMin(ways), D = FindMax(ways);
    std::set<std::string> center = FindCenter(ways, new_graph, R);
    long cyclomatic_num = static_cast<long long>(edges) - vertex + kComponentAmount;

    std::cout << "Второе:\n";
    std::cout << "\t|V|\t= " << vertex << '\n';
    std::cout << "\t|E|\t= " << edges << '\n';
    std::cout << "\tmin deg\t= " << min_deg << '\n';
    std::cout << "\tmax deg\t= " << max_deg << '\n';
    std::cout << "\tR\t= " << R << '\n';
    std::cout << "\tD\t= "<< D << '\n';
    std::cout << "\tЦентр(-ы):\t{";
    for (const auto& i : center) {
        std::cout << i << ", ";
    }
    std::cout << "}\n";
    std::cout << "\tЦикломатическое число\t= " << cyclomatic_num << "\n";
}

void Fourth(std::map<std::string, std::set<Path>>& graph) {
    std::vector<std::map<std::string, std::set<Path>>> components = Components(graph);
    std::cout << "Четвертое:\n";
    for (int i = 0; i < components.size(); ++i) {
        std::cout << '\t' << i + 1 << "-я: {";
        for (const auto& j : components[i]) {
            std::cout << j.first << ", ";
        }
        std::cout << "}\n";
    }
}

std::vector<Edge> MakeEdges(std::map<std::string, std::set<Path>>& graph) {
    std::vector<Edge> edges;
    for (const auto& i : graph) {
        for (const auto& j : i.second) {
            edges.emplace_back(i.first, j.name, j.weight);
        }
    }
    std::sort(edges.begin(), edges.end());
    return edges;
}

std::pair<std::vector<Edge>, unsigned long> MakeTree(std::map<std::string, std::set<Path>>& graph) {
    std::map<std::string, std::string> sets;
    for (const auto& i: graph) {
        sets[i.first] = i.first;
    }
    auto edges = MakeEdges(graph);
    std::vector<Edge> result;
    unsigned long cost = 0;
    for (const auto& e : edges) {
        if (sets[e.a] != sets[e.b]) {
            cost += e.weight;
            result.push_back(e);
            for (const auto& i : sets) {
                if (sets[i.first] == sets[e.b] && i.first != e.b) {
                    sets[i.first] = sets[e.a];
                }
            }
            sets[e.b] = sets[e.a];
        }
    }
    return {result, cost};
}

void Eleventh(std::map<std::string, std::set<Path>>& graph) {
    auto new_graph = MaxComponent(graph);
    auto result = MakeTree(new_graph);
    auto tree = result.first;
    unsigned long cost = result.second;

    std::cout << "Одинадцатое (просто список путей):\n";
    for (const auto& i : new_graph) {
        std::cout << "\t" << i.first << " -> {";
        for (const auto& j : tree) {
            if (i.first == j.a) {
                std::cout << j.b << " (" << j.weight << "), ";
            } else if (i.first == j.b) {
                std::cout << j.a << " (" << j.weight << "), ";
            }
        }
        std::cout << "}\n";
    }
    std::cout << "\n\tВес дерева: " << cost << '\n';
}

std::map<std::string, std::set<Path>> EdgesToGraph(const std::vector<Edge>& edges) {
    std::map<std::string, std::set<Path>> graph;
    for (const auto& i : edges) {
        graph[i.a].emplace(i.b, i.weight);
        graph[i.b].emplace(i.a, i.weight);
    }
    return graph;
}

void MakeCode(const std::string& node, const std::string& prev, std::map<std::string, std::set<Path>>& graph, std::string& ans, std::map<std::string, bool>& visited) {
    visited[node] = true;
    for (const auto& i : graph[node]) {
        if (!visited[i.name] && i.name != prev) {
            MakeCode(i.name, node, graph, ans, visited);
        }
    }
    if (!prev.empty()) {
        ans += prev + ", ";
    }
}

void Thirteenth(std::map<std::string, std::set<Path>>& graph) {
    auto new_graph = MaxComponent(graph);
    auto result = MakeTree(new_graph);
    auto tree = EdgesToGraph(result.first);
    std::map<std::string, bool> visited;
    for (const auto& i : tree) {
        visited[i.first] = false;
    }
    std::string ans;
    auto first = tree.begin()->first;
    MakeCode(first, "", tree, ans, visited);
    std::cout << "Тринадцатое\n\t" << ans << '\n';
}

int main() {
    std::setlocale(LC_ALL, "");
    auto graph = GetGraph();
    // проверяем, что граф не поломанный, все в нем чисто, ребра и названия везде совпадают, а иначе вылетит (y not?)
    Test(graph);
    std::cout << "Первое:\n\tВ файле и код наверху (он правда планарный)\n";
    Second(graph);
    std::cout << "Третье:\n\tПроще на рисунке\n";
    Fourth(graph);
    std::cout << "Пятое:\n\tНашел вручную\n";
    std::cout << "Шестое:\n\tКакое у нас там хроматическое число?\n";
    std::cout << "Седьмое-восьмое:\n\tНамно-о-о-ого проще вручную\n";
    std::cout << "Девятое-десятое:\n\tНевыполнимо\n";
    Eleventh(graph);
    std::cout << "Двенадцатое:\n\tНа бумаге (спойлер, 4)\n";
    Thirteenth(graph);
}