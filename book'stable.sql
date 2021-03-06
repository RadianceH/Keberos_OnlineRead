-- MySQL dump 10.13  Distrib 8.0.16, for Win64 (x86_64)
--
-- Host: 127.0.0.1    Database: vserver
-- ------------------------------------------------------
-- Server version	8.0.16

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
 SET NAMES utf8 ;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `book`
--

DROP TABLE IF EXISTS `book`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `book` (
  `bookname` varchar(36) DEFAULT NULL,
  `page` int(11) DEFAULT NULL,
  `content` varchar(512) NOT NULL,
  PRIMARY KEY (`content`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `book`
--

LOCK TABLES `book` WRITE;
/*!40000 ALTER TABLE `book` DISABLE KEYS */;
INSERT INTO `book` VALUES ('雪中悍刀行',2,' 今天王府很热闹，位高权重的北凉王亲自开了中门，摆开辉煌仪仗，迎接一位仙风道骨的老者，府中下人们只听说是来自道教圣地龙虎山的神仙，相中了痴痴傻傻的小王爷，要收作闭关弟子，这可是天大的福缘，北凉王府都解释成傻人有傻福。 可不是，小王爷自打出生起便没哭过，读书识字一窍不通，六岁才会说话，名字倒是威武气派，徐龙象，传闻还是龙虎山的老神仙当年给取的，说好十二年后再来收徒，这不就如约而至了。\n'),('雪中悍刀行',6,' 把北凉王给气得抬手作势要打，可抬着手僵持一会儿，就作罢。一来是不舍得打，二来是打了没意义。 这儿子可真对得起名字，徐龙象，取自“水行中龙力最大，陆行中象力第一，威猛如金刚，是谓龙象”，别看绰号黄蛮儿的傻儿子憨憨笨笨，至今斗大字不识，皮肤病态的暗黄，身形比较同龄人都要瘦弱，但这气力，却是一等一骇人。\n'),('碧玉刀',4,'“宝珠山庄”最珍贵的一粒宝珠，就是朱二太爷的掌上明珠。她今年才十七。她叫朱珠。据说朱二太爷今年破例做寿，就是为了替他的独生女选女婿。姑苏朱家是江南声名最显赫的武林世家，朱大小姐不但是有名的美人，还是有名的才女。听到了这消息，江湖中还未成亲的公子侠少们，只怕有一大半都会在四月十五之前赶到宝珠山庄。段玉是不是能雀屏中选，把这粒宝珠带回去，他实在没有把握。'),('倚天屠龙记',1,'“春游浩荡，是年年寒食，梨花时节。白锦无纹香烂漫，玉树琼苞堆雪。静夜沉沉，浮光霭霭，冷浸溶溶月。人间天上，烂银霞照通彻。浑似姑射真人，天姿灵秀，意气殊高洁。万蕊参差谁信道，不与群芳同列。浩气清英，仙才卓荦，下土难分别。瑶台归去，洞天方看清绝。”作这一首《无俗念》词的，乃南宋末年一位武学名家，有道之士。此人姓丘，名处机，道号长春子，名列全真七子之一，是全真教中出类拔萃的人物。'),('雪中悍刀行',5,'“黄蛮儿，你不是喜欢吃糖葫芦吗，那龙虎山遍地的野山楂，你随便摘随便啃。赵天师，是不是？”老神仙硬挤出一抹笑容，连连点头称是。收徒弟收到这份上，也忒寒碜了，说出去还不被全天下笑话。可哪怕位于堂堂超一品官职、在十二郡一言九鼎的大柱国口干舌燥了，少年还是没什么反应，估计是不耐烦了嫌老爹说得呱噪，翘起屁股，噗一下来了个响屁，还不忘扭头对老爹咧嘴一笑。'),('倚天屠龙记',2,'《词品》评论此词道：“长春，世之所谓仙人也，而词之清拔如此”。这首词诵的似是梨花，其实同中真意却是赞誉一位身穿白衣的美貌少女，说她“浑似姑射真人，天姿灵秀，意气殊高洁”，又说她“浩气清英，仙才卓荦”，“不与群芳同列”。词中所颂这美女，乃古墓派传人小龙女。她一生爱穿白衣，当真如风拂玉树，雪裹琼苞，兼之生性清冷，实当得起“冷浸溶溶月”的形容，以“无俗念”三字赠之，可说十分贴切。长春子丘处机和她在终南山上比邻而居，当年一见，便写下这首词来。'),('碧玉刀',7,'一、不可惹事生非，多管闲事。二、不可随意结交陌生的朋友。三、不可和陌生人赌钱。四、不可与僧道乞丐一类人结怨。五、钱财不可露白。六、不可轻信人言。第七条，也是最重要的一条，就是千万不可和陌生的女人来往。段玉一向是个很讨人喜欢的孩子，他不但健康英俊，彬彬有礼，而且很喜欢笑，很会笑，笑得很甜。何况他鲜衣怒马，年少多金，女人见了若不喜欢，那才是怪事。这本是段飞熊段老爷子最引以为傲的一点，现在却变成最担心的一点。'),('笑傲江湖',4,'五骑马一出城门，少镖头林平之双腿轻轻一挟，白马四蹄翻腾，直抢出去，片刻之间，便将后面四骑远远抛离。他纵马上了山坡，放起猎鹰，从林中赶了一对黄兔出来。他取下背上长弓，从鞍旁箭袋中取出一支雕翎，弯弓搭箭，刷的一声响，一头黄兔应声而倒，待要再射时，另一头兔却钻入草丛中不见了。郑镖头纵马赶到，笑道：“少镖头，好箭！”只听得趟子手白二在左首林中叫道：“少镖头，快来，这里有野鸡！”'),('雪中悍刀行',1,'北凉王府龙盘虎踞于清凉山，千门万户，极土木之盛。作为王朝硕果仅存的异姓王，在庙堂和江湖都是毁誉参半的北凉王徐骁作为一名功勋武臣，可谓得到了皇帝宝座以外所有的东西，在西北三州，他就是当之无愧的主宰，只手遮天，翻云覆雨。难怪朝廷中与这位异姓王政见不合的大人们私下都会文绉绉骂一声徐蛮子，而一些居心叵测的，更诛心地丢了顶“二皇帝”的帽子。\n'),('长生剑',5,'只听得他吐气开声，霹雳般一声大吼，竟将这匹马高高的举了起来，送到门檐上。白马又一声长嘶，马鬃飞舞，四条腿却似已钉在门檐上，动也不动。虬髯大汉仰天一声长笑，洒开大步，转瞬间也已走得不知去向，只留下一匹白马孤零零地站在暮云西风里，却显得说不出的诡异。 长街上已看不见人影，家家户户都闭上了门。风云客栈中也寂无人声，本来住店的客人，看到这一枚金环，八柄钢刀时，就早已从后门溜了。那匹白马却还是动也不动地站在西风里，就像是石头雕成的。'),('倚天屠龙记',4,'君应有语，渺万里层云，千山暮雪，只影向谁去？”她腰悬短剑，脸上颇有风尘之色，显是远游已久；韶华如花，正当喜乐无忧之年，可是容色间却隐隐有懊闷意，似是愁思袭人，眉间心上，无计回避。这少女姓郭，单名一个襄字，乃大侠郭靖和女侠黄蓉的次女，有个外号叫做“小东邪”。她一驴一剑，只身漫游，原想排遣心中愁闷，岂知酒入愁肠固然愁上加愁，而名山独游，一般的也是愁闷徒增。'),('笑傲江湖',1,'和风熏柳，花香醉人，正是南国春光漫烂季节。福建省福州府西门大街，青石板路笔直的伸展出去，直通西门。一座建构宏伟的宅第之前，左右两座石坛中各竖一根两丈来高的旗杆，杆顶飘扬青旗。右首旗上黄色丝线绣着一头张牙舞爪、神态威猛的雄狮，旗子随风招展，显得雄狮更奕奕若生。雄狮头顶有一对黑丝线绣的蝙蝠展翅飞翔。左首旗上绣着“福威镖局”四个黑字，银钩铁划，刚劲非凡。'),('笑傲江湖',2,'大宅朱漆大门，门上茶杯大小的铜钉闪闪发光，门顶匾额写着“福威镖局”四个金漆大字，下面横书“总号”两个小字。进门处两排长凳，分坐着八名劲装结束的汉子，个个腰板笔挺，显出一股英悍之气。突然间后院马蹄声响，那八名汉子一齐站起，抢出大门。只见镖局西侧门中冲出五骑马来，沿着马道冲到大门之前。当先一匹马全身雪臼，马勒脚镫都是烂银打就，鞍上一个锦衣少年，约莫十八九岁年纪，左肩上停着一头猎鹰，腰悬宝剑，背负长弓，泼喇喇纵马疾驰。'),('长生剑',3,'就在这时，暮色中却又驰来八匹健马，马蹄踏在石板大街上，如密雨敲窗，战鼓雷鸣。马上人一色青布箭衣，青帕包头，脚上搬尖洒鞋，系着倒赶千层浪的绑腿，一个个全都是神情剽悍，身手矫捷。八匹马在风云客栈门前飞驰而过，八个人同时一挥手。刀光如闪电般一亮，又是“夺”的一声响，海碗般粗的旗杆上，已多了八柄雪亮的钢刀。刀柄犹在不停地颤动，柄上的红绸刀衣“呼”的一声卷起。八匹马却已看不见了。 '),('雪中悍刀行',7,'徐骁十岁从军杀人，从东北锦州杀匈奴到南部灭大小六国屠七十余城再到西南镇压蛮夷十六族，什么样膂力惊人的猛将没有见过，但如小儿子这般可天生铜筋铁骨力拔山河的，真没有。 徐骁心中轻轻叹息，黄蛮儿若能稍稍聪慧一些，心窍多开一二，将来必定可以成为陷阵第一的无双猛将啊。他缓缓起身转头朝龙虎山辈分极高的道士尴尬一笑，后者眼神示意不打紧，只是心中难免悲凉。'),('笑傲江湖',6,'打了两个多时辰，林平之又射了两只兔子，两只雉鸡，只是没打到野猪和獐子之类的大兽，兴犹未足，说道：“咱们到前边山里再找找去。”史镖头心想：“这一进山，凭着少镖头的性儿，非到天色全黑决不肯罢手，咱们回去可又得听夫人的埋怨。”便道：“天快晚了，山里尖石多，莫要伤了白马的蹄子，赶明儿咱们起个早，再去打大野猪。”他知道不论说甚么话，都难劝得动这位任性的少镖头，但这匹白马他却宝爱异常，决不能让它稍有损伤。'),('碧玉刀',1,'春天。江南。段玉正少年。马是名种的玉面青花骢，配着鲜明的，崭新的全副鞍辔。马鞍旁悬着柄白银吞口，黑鲨皮鞘，镶着七颗翡翠的刀，刀鞘轻敲着黄铜马蹬，发出一串叮咚声响，就像是音乐。衣衫也是色彩鲜明的，很轻，很薄，剪裁得很合身，再配上特地从关外来的小牛皮软马靴，温洲“皮硝李”精制的乌梢马鞭，把手上还镶着比龙眼还大两分的明珠。现在正是暮春三月，江南草长，群莺乱飞的时候，一阵带着桃花芳香的春风，正吹过大地，温柔得就仿佛情人的呼吸。'),('长生剑',4,'暮色更浓，大街上突然又响起了一阵蹄声，仿佛比那八骑驰来时更急更密。但来的却只有一匹马。一匹白马，从头到尾，看不到丝毫杂色，到了客栈门前，突然一声长嘶，人立而起。大家这才看清马上的人，是个精赤着上身的虬髯大汉，一身黑肉就像是铁打的。这大汉收缰勒马，看见了门侧的金环赤发，也看见了旗杆上的八把刀，突然冷笑一声，自马鞍上一跃而下，左右双手握住了两条马腿。'),('长生剑',2,'朱红的灯笼，漆黑的字。“风云客栈”。九个赤发黄衫的怪人，走到客栈门前，停下脚步，当先一人摘下了耳上金环，一挥手，“夺”的，钉在漆黑大门旁的石墙上。火星四溅，金环竟嵌入石头里。第二人左手扯起肩上一束赤发，左掌轻轻一削，宛如刀锋。他将这束用掌缘割下来的赤发，系在金环上，九个人就又继续往前走。赤发火焰般在风中飞卷，这九个人却已消失在苍茫的暮色里。'),('笑傲江湖',5,'林平之纵马过去，只见林中飞出一只雉鸡，林平之刷的一箭，那野鸡对正了从他头顶飞来，这一箭竟没射中。林平之急提马鞭向半空中抽去，劲力到处，波的一声响，将那野鸡打了下来，五色羽毛四散飞舞。五人齐声大笑。史镖头道：“少镖头这一鞭，别说野鸡，便大兀鹰也打下来了！”五人在林中追逐鸟兽，史、郑两名镖头和趟子手白二、陈七凑少镖头的兴，总是将猎物赶到他身前，自己纵有良机，也不下手。'),('碧玉刀',3,'栏杆上的燕子被马蹄惊起，又呢喃着飞入桃花深处。段玉深深地吸了口气，只觉得自己轻松得就像这燕子一样，轻松得简直就像是要飞起来。 但是他也并非完全没有心事。家教一向最严的中原大豪段飞熊夫妇，当然不会无缘无故就放他们的独生子到江南来。段玉此行当然也有任务的。他的任务是在四月十五之前，赶到“宝珠山庄”去替他父亲少年时的八拜之交，“江南大侠”朱宽朱二太爷去拜寿，将段家祖传的宝物“碧玉刀”带去做寿礼，然后再把朱家的宝珠带回去。'),('倚天屠龙记',5,'河南少室山山势颇陡，山道却是一长列宽大的石级，规模宏伟，工程着实不小，那是唐朝高宗为临幸少林寺而开凿，共长八里。郭襄骑着青驴委折而上，只见对面山上五道瀑布飞珠溅玉，奔泻而下，再俯视群山，已如蚁蛭。顺着山道转过一个弯，遥见黄墙碧瓦，好大一座寺院。她望着连绵屋宇出了一会神，心想：“少林寺向为天下武学之源，但华山两次论剑，怎地五绝之中并无少林寺高僧？'),('雪中悍刀行',3,'王府内一处院落，龙虎山师祖一级的道门老祖宗捻着一缕雪白胡须，眉头紧皱，背负一柄不常见的小钟馗式桃木剑，配合他的相貌，确实当得出尘二字，谁看都要由衷赞一声世外高人呐。但此番收徒显然遇到了不小的阻碍，倒不是王府方面有异议，而是他的未来徒弟犟脾气上来了，蹲在一株梨树下，用屁股对付他这个天下道统中论地位能排前三甲的便宜师傅，至于武功嘛，咳咳，前三十总该有的吧。'),('长生剑',7,'白马竟似也懂得人意，立即展开四蹄，飞驰而去。中年文士随手拔下了门侧的金环，走入客栈，在旗杆上一敲。八把钢刀立刻同时落了下来。中年文士长袖又卷，已将这八柄刀卷在袖里，沉声道：“掌旗何在？”客栈中突然掠出一条瘦小的人影，猿猴般爬上旗杆，一眨眼间人已在杆头。杆头上立刻有一面大旗飞卷而出。雪白的旗帜上，绣着条张牙舞爪的乌黑长龙，仿佛也将破云飞去！ '),('碧玉刀',6,'的确还有一样，那就是他临出门时，他父亲板着面，耳提面命，再三嘱咐他，切切不可忘记的七大戒条。直到现在，他仿佛还能听见他父亲那种严厉的语声：“以你的聪明和武功，已勉强可以出去闯闯江湖了，但这几件事你还是千万不能去做，否则我保证你立刻就有麻烦上身。”“这是我积几十年经验得来的教训，你一定要牢记在心。”段玉从小就是个孝顺听话的孩子，这几样事他连一样都不敢忘记，每天早上一醒过来，都要在心里反复念几次：'),('倚天屠龙记',7,'瞥眼只见一块大碑上刻着唐太宗赐少林寺寺僧的御札，嘉许少林寺僧立功平乱。碑文中说唐太宗为秦王时，带兵讨伐王世充，少林寺和尚投军立功，最著者共一十三人。其中只昙宗一僧受封为大将军，其余十二僧不愿为官，唐太宗各赐紫罗袈裟一袭。她神驰想象：“当隋唐之际，少林寺武功便已名驰天下，数百年来精益求精，这寺中卧虎藏龙，不知有多少好手。”'),('碧玉刀',2,'绿水在春风中荡起了一圈圈涟漪，一双燕子刚刚从桃花林中飞出来，落在小桥的朱红栏杆上，呢喃私语，也不知在说些什么。段玉放松了缰绳，让座下的马，慢慢地踱过小桥。暖风迎面吹过来，吹起了他的薄绸青衫。就在这件紫绸衫左边的衣袋里，放着叠得整整齐齐的一叠崭新的银票，足够任何一个像他这样的年轻人，舒舒服服地花上三个月。他今年才十九，刚从千里冰封的北国，来到风光明媚的江南。'),('笑傲江湖',3,'身后跟随四骑，骑者一色青布短衣。一行五人驰到镖局门口，八名汉子中有三个齐声叫了起来：“少镖头又打猎去啦！”那少年哈哈一笑，马鞭在空中拍的一响，虚击声下，胯下白马昂首长嘶，在青石板大路上冲了出去。一名汉子叫道：“史镖头，今儿再抬头野猪回来，大伙儿好饱餐一顿。”那少年身后一名四十来岁的汉子笑道：“一条野猪尾巴少不了你的，可先别灌饱了黄汤。”众人大笑声中，五骑马早去得远了。'),('笑傲江湖',7,'这匹大宛名驹，是林平之的外婆在洛阳重价觅来，两年前他十七岁生日时送给他的。果然一听说怕伤马蹄，林平之便拍了拍马头，道：“我这小雪龙聪明得紧，决不会踏到尖石，不过你们这四匹马却怕不行。好，大伙儿都回去吧，可别摔破了陈七的屁股。”五人大笑声中，兜转马头。林平之纵马疾驰，却不沿原路回去，转而向北，疾驰一阵，这才尽兴，勒马缓缓而行。只见前面路旁挑出一个酒招子。'),('碧玉刀',5,'这就是段玉的心事。还有，段家的碧玉刀非但价值连城，而且故老相传，都说其中还藏着一个很大的秘密。无论谁只要能解开这秘密，他立刻就可能变成富可敌国的武林高手。江湖中的豪强大盗们，对这样东西眼红的自然也有不少。他是不是能将这件家传之宝平平安安地送到宝珠山庄去，他自己也没把握。这也是他的心事。但是在这江花红胜火，春水绿如蓝的江南三月，还有什么心事是一个十九岁的少年人抛不开，放不下的？'),('倚天屠龙记',3,'这时丘处机逝世已久，小龙女也已嫁与神雕大侠杨过为妻。在河南少室山山道之上，却另有一个少女，正在低低念诵此词。这少女十八九岁年纪，身穿淡黄衣衫，骑着一头青驴，正沿山道缓缓而上，心中默想：“也只有龙姊姊这样的人物，才配得上他。”这一个“他”字，指的自然是神雕大侠杨过了。她也不拉僵绳，任由那青驴信步而行，一路上山。过了良久，她又低声吟道：“欢乐趣，离别苦，就中更有痴儿女。'),('长生剑',6,'这时静寂的长街上，忽然又有个蓝衫白袜、面容清癯的中年文士，施施然走过来，神情仿佛很悠闲，但一双眸子里却闪着精光。他背负着双手，施施然走到客栈门前，抬头看了一眼，长叹道：“好马！端的是好马，只可惜主人无情，委曲你了。”他背负着的手突然一扬，长袖飞卷，带起了一阵急风。白马受惊，又是一声长嘶，从门檐上跃下。这中年文士双手一托，竟托住了马腹，将这匹马轻轻放在地上。他拍了拍马腹，道：“回去载你的主人来，就说这里有好朋友在等着他。”'),('雪中悍刀行',4,'连堂堂大柱国北凉王都得蹲在那里好言相劝，循循善诱里透着股诱拐，“儿子，去龙虎山学成一身本事，以后谁再敢说你傻，你就揍他，三品以下的文官武将，打死都不怕，爹给你撑腰。”“儿啊，你力气大，不学武捞个天下十大高手当当就太可惜了。学成归来，爹就给你一个上骑都尉当当，骑五花马，披重甲，多气派。”小王爷完全不搭理，死死盯着地面，瞧得津津有味。\n\n'),('倚天屠龙记',6,'难道寺中和尚自忖没有把握，生怕堕了威名，索性便不去与会？又难道众僧侣修为精湛，名心尽去，武功虽高，却不去和旁人争强赌胜？”她下了青驴，缓步走向寺前，只见树木森森，荫着一片碑林。石碑大半已经毁破，字迹模糊，不知写着些甚么。心想：“便是刻凿在石碑上的字，年深月久之后也须磨灭，如何刻在我心上的，却是时日越久反而越加清晰？”'),('长生剑',1,'黄昏。石板大街忽然出现了九个怪人，黄麻短衫，多耳麻鞋，左耳上悬着个碗大的金环，满头乱发竟都是赤红色的，火焰般披散在肩上。这九个人有高有矮，有老有少，容貌虽然不同，脸上却全都死人般木无表情，走起路来肩不动、膝不弯，也像是僵尸一样。他们慢慢地走过长街，只要是他们经过之处，所有的声音立刻全都停止，连孩子的哭声都被吓得突然停顿。大街尽头，一根三丈高的旗杆上，挑起四盏斗大的灯笼。');
/*!40000 ALTER TABLE `book` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `pubkey`
--

DROP TABLE IF EXISTS `pubkey`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `pubkey` (
  `userid` varchar(4) NOT NULL,
  `pubkey` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`userid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `pubkey`
--

LOCK TABLES `pubkey` WRITE;
/*!40000 ALTER TABLE `pubkey` DISABLE KEYS */;
/*!40000 ALTER TABLE `pubkey` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `user`
--

DROP TABLE IF EXISTS `user`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `user` (
  `userid` varchar(4) NOT NULL,
  `collect` varchar(36) DEFAULT NULL,
  PRIMARY KEY (`userid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `user`
--

LOCK TABLES `user` WRITE;
/*!40000 ALTER TABLE `user` DISABLE KEYS */;
/*!40000 ALTER TABLE `user` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2019-05-14 18:49:50
