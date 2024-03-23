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
    graph["�������"].emplace("����������", 209);
    graph["�������"].emplace("�������", 264);
    graph["�������"].emplace("����������", 212);
    graph["�������"].emplace("��������", 754);

    graph["����������"].emplace("�������", 209);
    graph["����������"].emplace("��������", 656);

    graph["��������"] = std::set<Path>();

    graph["����������"].emplace("��������", 761);
    graph["����������"].emplace("�������", 212);
    graph["����������"].emplace("�������", 287);

    graph["��������"].emplace("����������", 656);
    graph["��������"].emplace("�������", 754);
    graph["��������"].emplace("����������", 761);
    graph["��������"].emplace("�������", 1045);
    graph["��������"].emplace("���������", 444);
    graph["��������"].emplace("�������", 538);
    graph["��������"].emplace("�����", 635);
    graph["��������"].emplace("������", 670);
    graph["��������"].emplace("�����", 355);

    graph["������"].emplace("��������", 523);
    graph["������"].emplace("���������", 479);
    graph["������"].emplace("�����", 653);

    graph["��������"].emplace("������", 1643);
    graph["��������"].emplace("���������", 986);
    graph["��������"].emplace("������", 523);

    graph["������"].emplace("��������", 1643);
    graph["������"].emplace("���������", 892);
    graph["������"].emplace("������", 1151);
    graph["������"].emplace("�����", 791);
    graph["������"].emplace("������", 842);
    graph["������"].emplace("�������", 868);
    graph["������"].emplace("��������", 675);
    graph["������"].emplace("�������", 755);

    graph["��������������"].emplace("��������", 461);

    graph["���������"].emplace("��������", 444);
    graph["���������"].emplace("�������", 487);
    graph["���������"].emplace("������", 685);
    graph["���������"].emplace("�����������", 568);
    graph["���������"].emplace("�������", 591);

    graph["�����"].emplace("������", 653);
    graph["�����"].emplace("��������", 355);

    graph["���������"].emplace("������", 892);
    graph["���������"].emplace("��������", 986);
    graph["���������"].emplace("������", 479);

    graph["�������"].emplace("������", 868);
    graph["�������"].emplace("������", 279);

    graph["��������"].emplace("��������������", 461);

    graph["������"] = std::set<Path>();

    graph["�����������"].emplace("���������", 568);
    graph["�����������"].emplace("�������", 351);

    graph["�����"].emplace("��������", 635);
    graph["�����"].emplace("������", 571);
    graph["�����"].emplace("��������", 290);
    graph["�����"].emplace("�������", 251);

    graph["������"].emplace("��������", 670);
    graph["������"].emplace("������", 1151);
    graph["������"].emplace("�����", 571);
    graph["������"].emplace("��������", 532);
    graph["������"].emplace("�����", 393);
    graph["������"].emplace("�������", 689);
    graph["������"].emplace("��������", 475);

    graph["�����"].emplace("������", 791);
    graph["�����"].emplace("������", 261);
    graph["�����"].emplace("��������", 172);
    graph["�����"].emplace("������", 393);

    graph["������"].emplace("������", 842);
    graph["������"].emplace("�������", 279);
    graph["������"].emplace("��������", 402);
    graph["������"].emplace("�����", 261);

    graph["��������"].emplace("������", 675);
    graph["��������"].emplace("������", 402);
    graph["��������"].emplace("�����", 172);
    graph["��������"].emplace("������", 475);
    graph["��������"].emplace("�������", 433);

    graph["�������"].emplace("�������", 264);
    graph["�������"].emplace("����������", 287);
    graph["�������"].emplace("��������", 1045);
    graph["�������"].emplace("���������", 487);
    graph["�������"].emplace("������", 1105);
    graph["�������"].emplace("�������", 709);
    graph["�������"].emplace("�������", 1052);
    graph["�������"].emplace("������", 458);

    graph["������"].emplace("���������", 685);
    graph["������"].emplace("�������", 763);
    graph["������"].emplace("��������", 489);
    graph["������"].emplace("���-������", 227);
    graph["������"].emplace("�������", 4);
    graph["������"].emplace("�������", 1105);

    graph["�������"].emplace("������", 763);
    graph["�������"].emplace("�����������", 351);
    graph["�������"].emplace("���������", 591);
    graph["�������"].emplace("��������", 538);
    graph["�������"].emplace("�����", 251);
    graph["�������"].emplace("��������", 55);
    graph["�������"].emplace("�������", 215);
    graph["�������"].emplace("��������", 276);

    graph["��������"].emplace("�������", 55);
    graph["��������"].emplace("�����", 290);
    graph["��������"].emplace("������", 532);
    graph["��������"].emplace("�������", 1004);
    graph["��������"].emplace("�������", 162);

    graph["�������"].emplace("��������", 1004);
    graph["�������"].emplace("������", 689);
    graph["�������"].emplace("��������", 433);
    graph["�������"].emplace("������", 755);
    graph["�������"].emplace("�������������", 407);
    graph["�������"].emplace("��������", 400);
    graph["�������"].emplace("�������", 747);
    graph["�������"].emplace("�������", 898);

    graph["������"].emplace("�������", 458);

    graph["�������"].emplace("�������", 1052);
    graph["�������"].emplace("�������", 493);
    graph["�������"].emplace("����������", 503);

    graph["�������"].emplace("�������", 709);
    graph["�������"].emplace("�������", 493);

    graph["��������"].emplace("������", 489);
    graph["��������"].emplace("�������", 276);
    graph["��������"].emplace("�������", 489);
    graph["��������"].emplace("��������", 516);

    graph["����������"].emplace("�������", 503);

    graph["�������"].emplace("������", 4);
    graph["���-������"].emplace("������", 227);

    graph["��������"].emplace("��������", 516);
    graph["��������"].emplace("�������", 300);
    graph["��������"].emplace("������", 367);
    graph["��������"].emplace("������ � �����������", 405);
    graph["��������"].emplace("����������", 284);

    graph["�������"].emplace("��������", 300);
    graph["�������"].emplace("��������", 489);
    graph["�������"].emplace("�������", 215);
    graph["�������"].emplace("��������", 162);
    graph["�������"].emplace("�������", 898);
    graph["�������"].emplace("�������", 642);
    graph["�������"].emplace("������", 316);

    graph["�������"].emplace("�������", 642);
    graph["�������"].emplace("�������", 747);
    graph["�������"].emplace("��������", 358);
    graph["�������"].emplace("��������", 295);
    graph["�������"].emplace("������", 448);

    graph["��������"].emplace("�������", 358);
    graph["��������"].emplace("�������", 400);
    graph["��������"].emplace("�������������", 62);

    graph["�������������"].emplace("��������", 62);
    graph["�������������"].emplace("�������", 407);

    graph["������"] = std::set<Path>();

    graph["������ � �����������"].emplace("��������", 405);
    graph["������ � �����������"].emplace("������", 198);
    graph["������ � �����������"].emplace("����������", 179);

    graph["������"].emplace("������ � �����������", 198);
    graph["������"].emplace("��������", 367);
    graph["������"].emplace("�������", 316);
    graph["������"].emplace("�������", 448);
    graph["������"].emplace("��������", 329);
    graph["������"].emplace("���������", 323);
    graph["������"].emplace("������", 245);
    graph["������"].emplace("����������", 300);

    graph["��������"].emplace("������", 329);
    graph["��������"].emplace("�������", 295);
    graph["��������"].emplace("������", 503);
    graph["��������"].emplace("������", 526);
    graph["��������"].emplace("���������", 173);

    graph["������"].emplace("��������", 503);
    graph["������"].emplace("������", 561);

    graph["����������"].emplace("��������", 284);
    graph["����������"].emplace("������ � �����������", 179);
    graph["����������"].emplace("������", 300);
    graph["����������"].emplace("������", 157);
    graph["����������"].emplace("�������", 170);

    graph["������"].emplace("����������", 157);
    graph["������"].emplace("������", 245);
    graph["������"].emplace("���������", 77);
    graph["������"].emplace("�������", 251);

    graph["���������"].emplace("������", 77);
    graph["���������"].emplace("������", 323);
    graph["���������"].emplace("��������", 173);
    graph["���������"].emplace("������", 488);
    graph["���������"].emplace("�������", 153);

    graph["�������"].emplace("����������", 170);
    graph["�������"].emplace("������", 251);
    graph["�������"].emplace("���������", 153);
    graph["�������"].emplace("������", 501);

    graph["������"].emplace("�������", 501);
    graph["������"].emplace("���������", 488);
    graph["������"].emplace("��������", 526);
    graph["������"].emplace("������", 561);

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

    std::cout << "������:\n";
    std::cout << "\t|V|\t= " << vertex << '\n';
    std::cout << "\t|E|\t= " << edges << '\n';
    std::cout << "\tmin deg\t= " << min_deg << '\n';
    std::cout << "\tmax deg\t= " << max_deg << '\n';
    std::cout << "\tR\t= " << R << '\n';
    std::cout << "\tD\t= "<< D << '\n';
    std::cout << "\t�����(-�):\t{";
    for (const auto& i : center) {
        std::cout << i << ", ";
    }
    std::cout << "}\n";
    std::cout << "\t��������������� �����\t= " << cyclomatic_num << "\n";
}

void Fourth(std::map<std::string, std::set<Path>>& graph) {
    std::vector<std::map<std::string, std::set<Path>>> components = Components(graph);
    std::cout << "���������:\n";
    for (int i = 0; i < components.size(); ++i) {
        std::cout << '\t' << i + 1 << "-�: {";
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

    std::cout << "����������� (������ ������ �����):\n";
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
    std::cout << "\n\t��� ������: " << cost << '\n';
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
    std::cout << "�����������\n\t" << ans << '\n';
}

int main() {
    std::setlocale(LC_ALL, "");
    auto graph = GetGraph();
    // ���������, ��� ���� �� ����������, ��� � ��� �����, ����� � �������� ����� ���������, � ����� ������� (y not?)
    Test(graph);
    std::cout << "������:\n\t� ����� � ��� ������� (�� ������ ���������)\n";
    Second(graph);
    std::cout << "������:\n\t����� �� �������\n";
    Fourth(graph);
    std::cout << "�����:\n\t����� �������\n";
    std::cout << "������:\n\t����� � ��� ��� ������������� �����?\n";
    std::cout << "�������-�������:\n\t�����-�-�-��� ����� �������\n";
    std::cout << "�������-�������:\n\t�����������\n";
    Eleventh(graph);
    std::cout << "�����������:\n\t�� ������ (�������, 4)\n";
    Thirteenth(graph);
}