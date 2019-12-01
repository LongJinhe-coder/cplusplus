<template>
    <div>
        <el-container>
            <el-header>
                <userHelloWorld></userHelloWorld>
            </el-header>

            <el-main >
                
                <div class="subbody">                    
                    <p>
                        <font face="微软雅黑" size="7" style="float:left"> 文件</font>                           
                    </p>
                    <br>
                    <div style="float:left;">    
                        <el-select v-model="searchTag" slot="prepend" clearable placeholder="全部" size="mini" style="width:120px">
                            <el-option label="CQA" value="CQA"></el-option>
                            <el-option label="NER" value="NER"></el-option>
                            <el-option label="I/A" value="I/A"></el-option>                            
                        </el-select>    
                                      
                        <el-input placeholder="搜索文件" v-model="searchName" prefix-icon="el-icon-search" size="mini" style="width:200px">                            
                            <el-button slot="append"@click="search">搜索</el-button>                            
                        </el-input>                      
                    </div>
                    <div style="float:right">
                        <el-button size="mini" @click="uploadFormVisible = true">批量上传</el-button>                                                
                        <el-button size="mini" @click="downloadRows()">批量下载</el-button>
                        <el-button size="mini" @click="deleteRows()">批量删除</el-button>  
                        <el-button size="mini" @click="uploadFormVisible = true">上传文件</el-button>          
                    </div>

                    <!-- 表单 -->
                    <div>
                       <template>                                                                       
                            <el-table
                                ref="filterTable"
                                :data="apiData"
                                style="width: 100%"
                                @selection-change="handleSelectionChange">
                                
                                <el-table-column
                                    type="selection" width="55">
                                </el-table-column>
                                
                                <el-table-column
                                    prop="name"
                                    label="文件名称"
                                    width="100">
                                    <template slot-scope="scope">{{ scope.row.type }} {{ scope.row.name }}</template>
                                </el-table-column>

                                <el-table-column
                                    prop="file"
                                    label="配置文件"
                                    width="100">
                                </el-table-column>

                                <el-table-column
                                        prop="progress"
                                        label="进度">
                                    <template slot-scope="scope">
                                        <el-progress 
                                            :text-inside="true" 
                                            :stroke-width="24" 
                                            :percentage="scope.row.progress"
                                            :color="'#87CEEB'">
                                        </el-progress>
                                    </template>
                                    <!-- <el-tag type="info">{{scope.row.finishing}}/{{scope.row.finished}}</el-tag> -->
                                </el-table-column>
                                
                                <el-table-column
                                    prop="divece"
                                    label="分配人员"
                                    width="100">
                                </el-table-column>
                                
                                <el-table-column
                                    prop="date"
                                    label="截止时间"
                                    sortable
                                    width="180">
                                </el-table-column>
                                <el-table-column label="操作" width="200">
                                    <template slot-scope="scope">
                                        <el-tooltip class="item" effect="dark" content="设置任务" placement="top">
                                            <el-button 
                                            size="mini" circle  
                                            type="info" plain                                     
                                            icon="el-icon-setting"
                                            @click="handleSetting(scope.$index, scope.row);settingFromVisible = true"></el-button>
                                        </el-tooltip>
                                        <el-tooltip class="item" effect="dark" content="编辑配置文件" placement="top">
                                            <el-button
                                            size="mini" circle
                                            type="primary" plain
                                            icon="el-icon-edit"
                                            @click="handleEdit(scope.$index, scope.row)"></el-button>
                                        </el-tooltip>
                                        <el-tooltip class="item" effect="dark" content="重做" placement="top">
                                            <el-button
                                            size="mini" circle
                                            type="warning" plain
                                            icon="el-icon-refresh-left"
                                            @click="handleRedo(scope.$index, scope.row)"></el-button>
                                        </el-tooltip>
                                        <el-tooltip class="item" effect="dark" content="下载标记文件" placement="top">
                                            <el-button
                                            size="mini" circle
                                            type="success" plain
                                            icon="el-icon-download"
                                            @click="handleDownload(scope.$index, scope.row)"></el-button>
                                        </el-tooltip>                                    
                                        <el-tooltip class="item" effect="dark" content="删除" placement="top">
                                            <el-button
                                            size="mini" circle 
                                            type="danger" plain
                                            icon="el-icon-delete"
                                            @click="handleDelete(scope.$index, scope.row)"></el-button>
                                        </el-tooltip>                                                                                                                        
                                      </template>
                                </el-table-column>
                                
                            </el-table>
                        </template>
                    </div>

                    <!-- 翻页 -->
                    <div>
                         <el-pagination                           
                            @current-change="handleCurrentChange"
                            :current-page="currentPage"
                            :page-size="pagesize"
                            layout="total, prev, pager, next, jumper"
                            :total="totalPages">
                        </el-pagination>
                    </div>

                    <!-- 上传文件 -->
                    <el-dialog title="上传文件" :visible.sync="uploadFormVisible" width="40%">                                                 
                        <el-upload
                            class="upload1"
                            action="https://jsonplaceholder.typicode.com/posts/"
                            :on-change="handleChange"
                            :file-list="fileList1">
                            <el-button size="small" type="primary">上传文件</el-button>
                            <!-- <div slot="tip" class="el-upload__tip">只能上传jpg/png文件，且不超过500kb</div> -->
                        </el-upload>
                        <br>
                        <el-upload
                            class="upload2"
                            action="https://jsonplaceholder.typicode.com/posts/"
                            :on-change="handleChange"
                            :file-list="fileList2">
                            <el-button size="small" type="primary">上传配置文件</el-button>
                            <!-- <div slot="tip" class="el-upload__tip">只能上传jpg/png文件，且不超过500kb</div> -->
                        </el-upload>                       
                        <div slot="footer" class="dialog-footer">                            
                            <el-button @click="uploadFormVisible = false">取 消</el-button>
                            <el-button style="margin-left: 10px;" type="primary" 
                                @click="uploadFormVisible = false">上传</el-button>
                        </div>
                    </el-dialog>

                    <!-- 设置任务 -->
                    <el-dialog
                        title="设置任务"
                        :visible.sync="settingFromVisible"
                        width="40%"
                        :before-close="handleClose">
                        
                        <el-form :model="ruleForm" :rules="rules" ref="ruleForm" label-width="100px" class="demo-ruleForm">
                            
                            <el-form-item label="交叉验证" prop="ifTest">
                                <el-radio-group v-model="ruleForm.ifTest">
                                    <el-radio :label="1">是</el-radio>
                                    <el-radio :label="0">否</el-radio>
                                </el-radio-group>
                            </el-form-item>

                            <el-form-item label="分配人员" prop="checkedUsers">
                                <el-checkbox-group v-model="ruleForm.checkedUsers">                                
                                <el-checkbox v-for="user in users" :label="user" :key="user">{{user}}</el-checkbox>
                                </el-checkbox-group>
                            </el-form-item>

                            <el-form-item label="优先级" prop="priority">
                                <el-select v-model="ruleForm.priority" placeholder="请选择优先级">
                                    <el-option label="1" value="1"></el-option>
                                    <el-option label="2" value="2"></el-option>
                                    <el-option label="3" value="3"></el-option>
                                </el-select>
                            </el-form-item>

                            <el-form-item label="截止时间" required>                            
                                <el-form-item prop="date1">
                                    <el-date-picker type="datetime" placeholder="选择日期时间" v-model="ruleForm.date1" ></el-date-picker>                                   
                                </el-form-item>                                
                            </el-form-item>                            
                        </el-form>
                        
                        <span slot="footer" class="dialog-footer">
                            <el-button @click="settingFromVisible = false">取 消</el-button>
                            <el-button type="primary" @click="submitForm('ruleForm')">确 定</el-button>
                        </span>
                    </el-dialog>

                    <!-- 删除 弹框 -->
                    <el-dialog
                        title="确认删除"
                        :visible.sync="delFromVisible"
                        width="30%"
                        :before-close="handleClose">
                        <span>是否要删除</span>
                        <span slot="footer" class="dialog-footer">
                            <el-button @click="delFromVisible = false">取 消</el-button>
                            <el-button type="primary" @click="delFromVisible = false">确 定</el-button>
                        </span>
                    </el-dialog>

                </div>
                
              
            </el-main>
            <!-- <el-footer>Footers</el-footer> -->
        </el-container>
    </div>

</template>

<script>
    //导入导航栏组件
    import userHelloWorld from "../components/userHelloWorld.vue";
    // import { compileFunction } from 'vm';
    // import { isNull } from 'util';
    export default {
        //分页
        mounted: function() {            
            this.$axios.get("/files/getallfiles/?page=1").then(res => {
                console.log(res.data);
                if (res.data.code == 200) {
                    this.totalPages = res.data.total_page;
                    this.pagesize = res.data.data.length;                    
                    
                    var maxpage=this.totalPages/this.pagesize+1;
                    if(this.currentPage>maxpage){
                        this.currentPage=maxpage;
                    }
                    var min=(this.currentPage-1)*this.pagesize;
                    var max=this.currentPage*this.pagesize-1;
                    res.data.data.forEach(
                        (item,key)=>{
                            if(key>=min &&key<=max){
                                //this.realData[key]=item;
                                console.log(item.mission_id);
                                this.realData[key].taskID=item.mission_id;
                                this.realData[key].type=item.mark_type;
                                this.realData[key].name=item.mission_title;
                                // this.realData[key].ddl=formatDate(item.finished_data, 'yyyy-MM-dd hh:mm');
                                // this.realData[key].date=formatDate(item.submit_time, 'yyyy-MM-dd hh:mm');
                                this.realData[key].configID=item.config_file_id;                                                   
                                this.realData[key].config=item.config_file_name;
                                this.realData[key].finishing=item.all_data;
                                this.realData[key].finished=item.finished_data;
                                //this.realData[key].progress =80;
                                //this.realData[key].progress=parseInt(item.finished_data/item.all_data*100);  
                                //this.realData[key].workers=item.mission_id;
                                //this.realData[key].isTest=item.mission_id;
                                this.realData[key].priority=item.priority;
                            }                   
                        }
                    )
                    console.log(this.realData);
                }
            });
   
        },
        data() {
            return {
                avataUrl:"http://img2.imgtn.bdimg.com/it/u=3749323882,846155126&fm=26&gp=0.jpg",
                // avataUrl:require('../assets/headPortrait (2).jpg') ,
                fileList1: [],
                fileList2: [],
                apiData: [
                    {
                        taskID:1,//任务id
                        type:'NER',//标注类型
                        name: '儿科',//文件名称
                        date:'2016-05-01',//截止日期（年月日时分秒）
                        finishing: 100,//总任务
                        finished:200,//已完成任务
                        progress: 50,//进度（百分比）
                        //url:'www.baidu.com',//文件地址
                        config:'',//配置文件名称
                        //configUrl:'',//配置文件地址
                        workers:[],//分配人员
                        isTest:0,//是否交叉验证
                        priority:1,//任务优先级
                    },
                    {
                        taskID:2,
                        type:'NER',
                        name: '植发科',
                        date:'2016-05-01',
                        progress: 70,
                        url:'',
                        config:'',
                        configUrl:'',
                        workers:[],
                        isTest:0,
                        priority:1,
                    },
                    {
                        taskID:3,
                        type:'CQA',
                        name: '儿科',
                        date:'2016-05-01',
                        progress: 30,
                        url:'',
                        config:'',
                        configUrl:'',
                        workers:[],
                        isTest:0,
                        priority:1,
                    }, 
                    {
                        taskID:4,
                        type:'CQA',
                        name: '植发科',
                        date:'2016-05-01',
                        progress: 100,
                        url:'',
                        config:'',
                        configUrl:'',
                        workers:[],
                        isTest:0,
                        priority:1,
                    }, 
                    
                ],
                tableData:[],
                realData:[
                    {
                        taskID:'',
                        type:'',
                        name:'',
                        ddl:'',
                        date:'',
                        configID:'',
                        config:'',
                        finishing:'',
                        finished:'',
                        progress:80,
                        workers:[],
                        priority:'',
                        isTest:'',
                        priority:'',                                
                    },
                    {
                        taskID:'',
                        type:'',
                        name:'',
                        ddl:'',
                        date:'',
                        configID:'',
                        config:'',
                        finishing:'',
                        finished:'',
                        progress:80,
                        workers:[],
                        priority:'',
                        isTest:'',
                        priority:'',                                
                    },
                    {
                        taskID:'',
                        type:'',
                        name:'',
                        ddl:'',
                        date:'',
                        configID:'',
                        config:'',
                        finishing:'',
                        finished:'',
                        progress:80,
                        workers:[],
                        priority:'',
                        isTest:'',
                        priority:'',                                
                    },
                    {
                        taskID:'',
                        type:'',
                        name:'',
                        ddl:'',
                        date:'',
                        configID:'',
                        config:'',
                        finishing:'',
                        finished:'',
                        progress:80,
                        workers:[],
                        priority:'',
                        isTest:'',
                        priority:'',                                
                    },
                    {
                        taskID:'',
                        type:'',
                        name:'',
                        ddl:'',
                        date:'',
                        configID:'',
                        config:'',
                        finishing:'',
                        finished:'',
                        progress:80,
                        workers:[],
                        priority:'',
                        isTest:'',
                        priority:'',                                
                    },
                    {
                        taskID:'',
                        type:'',
                        name:'',
                        ddl:'',
                        date:'',
                        configID:'',
                        config:'',
                        finishing:'',
                        finished:'',
                        progress:80,
                        workers:[],
                        priority:'',
                        isTest:'',
                        priority:'',                                
                    },
                    {
                        taskID:'',
                        type:'',
                        name:'',
                        ddl:'',
                        date:'',
                        configID:'',
                        config:'',
                        finishing:'',
                        finished:'',
                        progress:80,
                        workers:[],
                        priority:'',
                        isTest:'',
                        priority:'',                                
                    },
                    {
                        taskID:'',
                        type:'',
                        name:'',
                        ddl:'',
                        date:'',
                        configID:'',
                        config:'',
                        finishing:'',
                        finished:'',
                        progress:80,
                        workers:[],
                        priority:'',
                        isTest:'',
                        priority:'',                                
                    },
                    {
                        taskID:'',
                        type:'',
                        name:'',
                        ddl:'',
                        date:'',
                        configID:'',
                        config:'',
                        finishing:'',
                        finished:'',
                        progress:80,
                        workers:[],
                        priority:'',
                        isTest:'',
                        priority:'',                                
                    },
                    {
                        taskID:'',
                        type:'',
                        name:'',
                        ddl:'',
                        date:'',
                        configID:'',
                        config:'',
                        finishing:'',
                        finished:'',
                        progress:80,
                        workers:[],
                        priority:'',
                        isTest:'',
                        priority:'',                                
                    },
                   
                ],
                searchTag:'',
                searchName:'',
                currentPage:1,
                pagesize:10,
                totalPages:'',
                ruleForm:{ //设置任务
                    taskID:'',
                    ifTest:'',
                    checkedUsers:[],
                    priority:'',
                    date1: ''                                        
                },
                settingData:{
                    taskID:'',//misson_id
                    ifTest:'',
                    checkedUsers:[],
                    priority:'',
                    date1: ''  
                },
                rules:{//设置任务校验
                    ifTest:[
                        { required: true, message: '请选择是否交叉验证', trigger: 'change' }
                    ],
                    checkedUsers:[
                        { type: 'array', required: true, message: '请至少选择一个分配人员', trigger: 'change' }
                    ],
                    priority:[
                        { required: true, message: '请选择优先级', trigger: 'change' }
                    ],
                    date1: [
                        { type: 'date', required: true, message: '请选择日期', trigger: 'change' }
                    ]           
                },
                sels:[],//批量操作选中的值                
                users:['用户1','用户2','用户3'],//设置任务的人员
                uploadFormVisible:false,
                settingFromVisible:false,
                delFromVisible:false,
                test:['1','2'],
                uploadform: {
                    avataUrl:"http://img2.imgtn.bdimg.com/it/u=3749323882,846155126&fm=26&gp=0.jpg",
                    name: '请输入用户名',
                    birthDate:'',
                    tel:'',
                    email:'',
                    gander:'',                    
                }
            }

        },
        methods: {
            //分页
            // cartView: function() {
            //     this.totalPages = this.tableData.length;

            //     var maxpage=this.totalPages/this.pagesize+1;
            //     if(this.currentPage>maxpage){
            //         this.currentPage=maxpage;
            //     }
            //     var min=(this.currentPage-1)*this.pagesize;
            //     var max=this.currentPage*this.pagesize-1;
            //     this.tableData.forEach(
            //         (item,key)=>{
            //             if(key>=min &&key<=max){
            //                 this.realData[key]=item;    
            //             }                   
            //         }
            //     )
            //     console.log(this.realData);               
            // },
             //切换页码
            handleCurrentChange(val) {
                this.realData = [];
                this.totalPages = this.tableData.length;//4
                this.currentPage=val;//2
                var maxpage=this.totalPages/this.pagesize+1;//2
                if(this.currentPage>maxpage){
                    this.currentPage=maxpage;
                    
                }
                var min=(this.currentPage-1)*this.pagesize;//3
                var max=this.currentPage*this.pagesize-1;//5                      
                var i = 0;
                this.tableData.forEach(
                    (item,key)=>{                        
                        if(key>=min && key<=max){
                            if(i<this.pagesize){
                                this.realData[i]=item;
                                i++;
                            }                                
                        }                   
                    }
                )
                console.log(this.realData);
                console.log(`当前页: ${val}`);
            },            
            
            //设置任务
            submitForm(formName) {
                this.$refs[formName].validate((valid) => {
                    if (valid) {                        
                        this.settingData.taskID=this.ruleForm.taskID;
                        this.settingData.ifTest=this.ruleForm.ifTest;
                        this.settingData.checkedUsers=this.ruleForm.checkedUsers;
                        this.settingData.priority=this.ruleForm.priority;
                        this.settingData.date1=this.ruleForm.date1;
                        console.log(this.settingData);
                        alert('设置成功');
                        this.settingFromVisible = false;
                        this.$refs[formName].resetFields();
                    } else {
                        console.log('设置失败');
                        return false;
                    }
                });
                
            },
            
            //上传
            handleChange(file, fileList) {
                this.fileList = fileList.slice(-3);
                console.log();
            },
            //多选
            handleSelectionChange(val) {
                this.sels = val;
            },           
            handleClose(done) {
                this.$confirm('确认关闭？')
                .then(_ => {
                    done();
                })
                .catch(_ => {});
            },
            //批量上传
            downloadRows(rows){
                
            },
            //批量删除
            deleteRows(){
                // console.log(rows);
                // if (rows) {
                //     rows.forEach(row => {
                //         console.log(row); 
                //         this.$refs.filterTable.toggleRowSelection(row);
                //     });
                // } else {
                //     this.$refs.filterTable.clearSelection();
                // }
                console.log(this.sels);
                var ids= this.sels.map(item => item.type+item.name).join()//获取所有选中行的id组成的字符串，以逗号分隔
                console.log(ids)
                // this.sels.forEach(
                //     (item,key)=>{
                //         if(key>=min &&key<=max){
                //             this.realData[key]=item;    
                //         }                   
                //     }
                // )
                
                this.$confirm('确认删除 '+ ids +' 文件?', '提示', {
                    confirmButtonText: '确定',
                    cancelButtonText: '取消',
                    type: 'warning'
                }).then(() => {      
                    console.log("删除成功")
                })
        

            },
            //单个设置任务
            handleSetting(index, row){
                this.ruleForm.taskID=row.taskID;                
            },
            //单个编辑配置文件
            handleEdit(index, row){

            },
            //单个重做
            handleRedo(index, row){

            },
            //单个下载文件   
            handleDownload(index, row){                
                if(row.url){
                    console.log(row.url);
                    window.open(row.url);
                }
                else{
                    console.log('下载失败');
                        return false;
                }
                
            },
            //单个删除           
            handleDelete(index, row) {
                this.$confirm('此操作将永久删除该文件, 是否继续?', '提示', {
                confirmButtonText: '确定',
                cancelButtonText: '取消',
                type: 'warning'
                }).then(() => {
                    console.log(index, row);
                    this.$message({
                        type: 'success',
                        message: '删除成功!'
                    });
                }).catch(() => {
                    this.$message({
                        type: 'info',
                        message: '已取消删除'
                    });          
                });
            },
            //搜索
            search(){                        
                if(this.searchName.length==0 && this.searchTag.length==0) {
                    this.tableData = this.apiData;
                    this.handleCurrentChange(1);
                }
                else if (this.searchName.length!=0 && this.searchTag.length==0){
                    this.tableData =  this.apiData.filter(item=>{       
                        if (item.name.includes(this.searchName)){                           
                            return item;
                        }
                    });
                    this.handleCurrentChange(1);
                }
                else if(this.searchName.length==0 && this.searchTag.length!=0){
                    this.tableData =  this.apiData.filter(item=>{       
                        if (item.type.includes(this.searchTag)){                            
                            return item;
                        }
                    });
                    this.handleCurrentChange(1);
                }
                else {
                    this.tableData =  this.apiData.filter(item=>{       
                        if (item.type.includes(this.searchTag) && item.name.includes(this.searchName)){                            
                            return item;
                        }
                    });
                    this.handleCurrentChange(1);
                }        
            },


        },
        
        name: "homepage",
        components: {
            userHelloWorld
        }
    };
</script>

<style>
    .headLabel {
        width: 1800px;
        height: 130px;
        max-height: 100%;
        max-width: 100%;
        background: url('../assets/personal-center_02.png') center center no-repeat;
        background-position:center;
        background-size:100%;

    }
    .subbody{
        width: 1000px;
        height: 600px;
        text-align: center;
        margin:0 auto;
    }
    
</style>