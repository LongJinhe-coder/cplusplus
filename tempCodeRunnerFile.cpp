cout<<"插入一个元素"<<endl;
    int a;
    cin>>a;
    char messages[10];
    cin>>messages;
    int counting;
    // count=0;
    InsertTrees(t,a,messages,counting);
    cout<<"插入的元素在第"<<counting<<"层"<<endl;