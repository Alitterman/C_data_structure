    int n;

    scanf("%d",&n);
    // cin >> n;
    for (int i = 0; i < n; i++)
    {
        // cin >> x >> y >> z;
        scanf("%d %d %d",&x,&y,&z);
        printf("Case #%d: %s\n",i+1,x+y>z?"true":"false");
        // if(x+y>z){
            
        //     // cout << "Case #"<< i+1 << ": true"<<endl;
        // }
        // else{
        //     // cout << "Case #"<< i+1 << ": false"<<endl;
        // }
    }
    getchar();