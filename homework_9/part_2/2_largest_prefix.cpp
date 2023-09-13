using namespace std;

#include<vector>
#include<map>


class LUPrefix {
    vector<bool> upload_video;
    int longest_prefix;
public:
    LUPrefix(int n) {
        upload_video.assign(n, false);
        longest_prefix = 0;
    }
    
    void upload(int video) {
        upload_video[video-1] = true;
        
        int i = longest_prefix;
        while(upload_video[i] && i < upload_video.size())
        {
            longest_prefix = i+1;
            i++;
        }
    }
    
    int longest() {
        return longest_prefix;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */