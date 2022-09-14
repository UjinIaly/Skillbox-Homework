#include <iostream>
#include <vector>
#include <map>

class IGraph{
public:
    IGraph(){};
    IGraph(IGraph *other){};
    virtual ~IGraph(){}
    virtual void Add_edge(size_t from, size_t to) = 0;
    virtual size_t Vertices_count() const = 0;
    virtual void get_next_vertices(size_t vertex, std::vector<size_t> &vertices) = 0;
    virtual void get_prev_vertices(size_t vertex, std::vector<size_t> &vertices) = 0;
};

class adjacency_list: public IGraph {
private:
    size_t vertices_count;
    std::map<size_t, std::vector<size_t>> list;
public:
    adjacency_list(size_t _vertices):vertices_count(_vertices){
        for(size_t i = 0;i<vertices_count;++i){
            list.insert(std::pair<size_t,std::vector<size_t>>(i, 0));
        }
    };

    void show(){
        for(std::map<size_t,std::vector<size_t>>::iterator it = list.begin(); it!=list.end();++it){
            std::cout<<it->first+1;
            for(size_t i = 0;i<it->second.size();++i){
                std::cout<<" -> "<<it->second[i];
            }
            std::cout<<std::endl;
        }
    }
    void Add_edge(size_t from, size_t to) override{
        std::map<size_t,std::vector<size_t>>::iterator it = list.find(from-1);
        for(size_t i =0;i<it->second.size();++i){
            if(to == it->second[i]){
                std::cout<<" already exist"<<it->first+1<<" -> "<<it->second[i]<<std::endl;
                return;
            }
        }
        it->second.push_back(to);
    }
    size_t Vertices_count() const override{
        return vertices_count;
    };
    void get_next_vertices(size_t vertex, std::vector<size_t> &vertices)override {
        std::map<size_t,std::vector<size_t>>::iterator it = list.find(vertex-1);
        for(size_t i = 0;i<it->second.size();++i){
            vertices[i] = it->second[i];
        }
        std::cout<<std::endl;
    };
    void get_prev_vertices(size_t vertex, std::vector<size_t> &vertices) override{
        int count = 0;
        for(std::map<size_t,std::vector<size_t>>::iterator it = list.begin();it!=list.end();++it){
            for(size_t i = 0;i<it->second.size();++i){
                if(it->second[i] == vertex){
                    vertices[count] = it->first+1;
                    ++count;
                }
            }
        }
    };

};
class adjacency_matrix : public IGraph {
private:
    std::vector<std::vector<size_t>> matrix;
    size_t vertices_count;
public:
    adjacency_matrix(size_t vertices):vertices_count(vertices){
        matrix.assign(vertices_count,std::vector<size_t> (vertices_count));
        for(size_t i = 0;i<vertices_count;++i){
            for(size_t j = 0;j<vertices_count;++j){
                matrix[i][j] = 0;
            }
        }
    }

    void show(){
        for(size_t i = 0;i<vertices_count;++i){
            for(size_t j = 0;j<vertices_count;++j){
                std::cout<<matrix[i][j]<<" ";
            }
            std::cout<<std::endl;
        }
    }
    size_t Vertices_count() const override{
        return vertices_count;
    };
    virtual void Add_edge(size_t from, size_t to) {
        matrix[from-1][to-1] = 1;
    };
    void get_next_vertices(size_t vertex, std::vector<size_t> &vertices) override{
        size_t count = 0;
        for(size_t i = 0;i<vertices_count;++i){
            if(matrix[vertex-1][i] == 1){
                vertices[count++] = i+1;
            }
        }
    };
    void get_prev_vertices(size_t vertex, std::vector<size_t> &vertices) override{
        size_t count = 0;
        for(size_t i = 0;i<vertices_count;++i){
            if(i == vertex-1){ continue;}
            for(size_t j=0;j<vertices_count;++j){
                if(matrix[i][j] == 1&&j==vertex-1){
                    vertices[count++] = i+1;
                }
            }
        }
    };



};

int main() {


}
