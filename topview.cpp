map<int,pair<int,int>>mp;

 void topview(Node * root,int dist,int level){
    if(root==NULL){
        return ;
    }
    if(mp.find(dist)!=mp.end()){
        if(level<mp[dist].second){
            mp[dist].first=root->data;
            mp[dist].second=level;
        }
    }
    else{
        mp.insert(make_pair(dist,make_pair(root->data,level)));
    }
    topview(root->left,dist-1,level+1);
    topview(root->right,dist+1,level+1);
 } 

 void topviewhelper(Node *root){
    topview(root,0,0);
    cout<<"top view\n";
    for(auto x:mp){
        cout<<x.second.first<<" ";
    }
 }