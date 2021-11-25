//
//  SecondAuth.m
//  NativeSample
//
//  Created by yettie on 2021/01/22.
//

#import "SecondAuth.h"
#import "Network.h"

@implementation SecondAuth{
    NSString *authURL;
    void (^_onSecondAuthCallback)(int result, NSString *resJsonStr);
}

- (instancetype)init:(NSString *)url{
    self = [super init];
    if (self) {
        authURL = url;
    }
    return self;
}

-(void)sendServer:(NSString *)jsonStr
         callback:(void (^)(int code,
                            NSString *resjsonStr))onResponseCallback{
    int result = 0;
    __block void (^_onCallback)(int code,
                                NSString *jsonStr);
    __block NSString *_jsonStr;
    NSMutableURLRequest *request = nil;
    Network *network = [[Network alloc]init];
    
    if(jsonStr == nil || jsonStr.length==0){
        //invaild input..
        result = -10000;
        goto end;
    }
    _jsonStr = jsonStr;
    _onCallback = onResponseCallback;
    
    request  = [network makeRequest:authURL withJsonBody:[jsonStr dataUsingEncoding:NSUTF8StringEncoding]];
    if(request == nil){
        //failed generate_Post...
        result = -10000;
        goto end;
    }
    
    [network sendServlet:request callback:^(int code, NSString * _Nullable jsonStr) {
        _onCallback(result,jsonStr);
        return;
    }];
    
end:
    if(result!=0){
        _onCallback(result,nil);
        return;
    }
}

-(void)regKey:(NSMutableDictionary *)regKeyDict
     callback:(void (^)(int code,
                        NSString *jsonStr))onRegKeyCallback{
         
    int result = 0;
    __block SecondAuth *_blockSelf = self;
    [_blockSelf initiazeCallback:_blockSelf callback:onRegKeyCallback];
    
    NSMutableString *queryString = [[NSMutableString alloc]initWithString:PRMMODE];
    [queryString appendFormat:@"=%@",@"modeRegKey"];
    [queryString appendFormat:@"&%@",PRMSIGNATURE];
    [queryString appendFormat:@"=%@",[self urlencode:[regKeyDict objectForKey:@"signedData"]]];
    [queryString appendFormat:@"&%@",PRMPUB1];
    [queryString appendFormat:@"=%@",[self urlencode:[regKeyDict objectForKey:@"pub1"]]];
    [queryString appendFormat:@"&%@",PRMTOKEN];
    [queryString appendFormat:@"=%@",[self urlencode:[regKeyDict objectForKey:@"token"]]];
    [queryString appendFormat:@"&%@",PRMFINGERPRINT];
    [queryString appendFormat:@"=%@",[self urlencode:[regKeyDict objectForKey:@"fingerPrint"]]];
    [queryString appendFormat:@"&%@",PRMNICKNAME];
    [queryString appendFormat:@"=%@",[self urlencode:[regKeyDict objectForKey:@"nickName"]]];
    NSLog(@"check regKey queryString %@",queryString);
    
    [_blockSelf sendServer:queryString callback:^(int code, NSString * _Nonnull resjsonStr) {
        _blockSelf->_onSecondAuthCallback(code, resjsonStr);
        return;
    }];
end:
    if(result!=0){
        _blockSelf->_onSecondAuthCallback(result,nil);
        return;
    }
}
-(void)authKey:(NSMutableDictionary *)authKeyDict
     callback:(void (^)(int code,
                        NSString *jsonStr))onAuthKeyCallback{
    
    int result = 0;
    __block SecondAuth *_blockSelf = self;
    [_blockSelf initiazeCallback:_blockSelf callback:onAuthKeyCallback];
    
    NSMutableString *queryString = [[NSMutableString alloc]initWithString:PRMMODE];
    [queryString appendFormat:@"=%@",@"modeAuthKey"];
    [queryString appendFormat:@"&%@",PRMSIGNATURE];
    [queryString appendFormat:@"=%@",[self urlencode:[authKeyDict objectForKey:@"signedData"]]];
    [queryString appendFormat:@"&%@",PRMPUB2];
    [queryString appendFormat:@"=%@",[self urlencode:[authKeyDict objectForKey:@"pub2"]]];
    [queryString appendFormat:@"&%@",PRMTOKEN];
    [queryString appendFormat:@"=%@",[self urlencode:[authKeyDict objectForKey:@"token"]]];
    [queryString appendFormat:@"&%@",PRMFINGERPRINT];
    [queryString appendFormat:@"=%@",[self urlencode:[authKeyDict objectForKey:@"fingerPrint"]]];
    NSLog(@"check authKey queryString %@",queryString);
    
    [_blockSelf sendServer:queryString callback:^(int code, NSString * _Nonnull resjsonStr) {
        _blockSelf->_onSecondAuthCallback(code, resjsonStr);
        return;
    }];
end:
    if(result!=0){
        _blockSelf->_onSecondAuthCallback(result,nil);
        return;
    }
}

- (void)signVerify:(NSMutableDictionary *)signVerifyDict
          callback:(void (^)(int, NSString * _Nullable))onSignVerifyCallback{
    int result = 0;
    __block SecondAuth *_blockSelf = self;
    NSMutableDictionary *_signDict;
    [_blockSelf initiazeCallback:_blockSelf callback:onSignVerifyCallback];
    
    NSMutableString *queryString = [[NSMutableString alloc]initWithString:PRMMODE];
    [queryString appendFormat:@"=%@",@"modeAuthNSignVerify"];
    [queryString appendFormat:@"&%@",PRMAUTHSIGNATURE];
    [queryString appendFormat:@"=%@",[self urlencode:[signVerifyDict objectForKey:@"signedData"]]];
    [queryString appendFormat:@"&%@",PRMORGDATASIGNATURE];
    
    //첫번째 배열에 담겨서 옴..
    _signDict = [signVerifyDict objectForKey:@"orgSignature"][0];
    [queryString appendFormat:@"=%@",[self urlencode:[_signDict objectForKey:@"userSignedData"]]];
    [queryString appendFormat:@"&%@",PRMORGDATA];
    [queryString appendFormat:@"=%@",[self urlencode:[signVerifyDict objectForKey:@"orgData"]]];
    [queryString appendFormat:@"&%@",PRMPUB2];
    [queryString appendFormat:@"=%@",[self urlencode:[signVerifyDict objectForKey:@"pub2"]]];
    [queryString appendFormat:@"&%@",PRMTOKEN];
    [queryString appendFormat:@"=%@",[self urlencode:[signVerifyDict objectForKey:@"token"]]];
    [queryString appendFormat:@"&%@",PRMFINGERPRINT];
    [queryString appendFormat:@"=%@",[self urlencode:[signVerifyDict objectForKey:@"fingerPrint"]]];
    NSLog(@"check signVerify queryString %@",queryString);
    
    [_blockSelf sendServer:queryString callback:^(int code, NSString * _Nonnull resjsonStr) {
        _blockSelf->_onSecondAuthCallback(code, resjsonStr);
        return;
    }];
end:
    if(result!=0){
        _blockSelf->_onSecondAuthCallback(result,nil);
        return;
    }
}

- (void)multiSign:(NSMutableDictionary *)multiSignDict
          callback:(void (^)(int, NSString * _Nullable))onMultiSignCallback{
    int result = 0;
    __block SecondAuth *_blockSelf = self;
    [_blockSelf initiazeCallback:_blockSelf
                        callback:onMultiSignCallback];
    
    NSMutableString *queryString = [[NSMutableString alloc]initWithString:PRMMODE];
    NSString *multiSignJsonStr;
    [queryString appendFormat:@"=%@",@"modeAuthNSignVerify"];
    [queryString appendFormat:@"&%@",PRMAUTHSIGNATURE];
    [queryString appendFormat:@"=%@",[self urlencode:[multiSignDict objectForKey:@"signedData"]]];
    [queryString appendFormat:@"&%@",PRMMULTISIGNEDDATA];
    
    result = [self makejsonStrFromArray:[multiSignDict objectForKey:@"multiSignedData"]
                            withJsonStr:&multiSignJsonStr];
    if(result!=0){
        goto end;
    }
    
    [queryString appendFormat:@"=%@",[self urlencode:multiSignJsonStr]];
    [queryString appendFormat:@"&%@",PRMPUB2];
    [queryString appendFormat:@"=%@",[self urlencode:[multiSignDict objectForKey:@"pub2"]]];
    [queryString appendFormat:@"&%@",PRMTOKEN];
    [queryString appendFormat:@"=%@",[self urlencode:[multiSignDict objectForKey:@"token"]]];
    [queryString appendFormat:@"&%@",PRMFINGERPRINT];
    [queryString appendFormat:@"=%@",[self urlencode:[multiSignDict objectForKey:@"fingerPrint"]]];
    NSLog(@"check multiSign queryString %@",queryString);
    
    [_blockSelf sendServer:queryString callback:^(int code, NSString * _Nonnull resjsonStr) {
        _blockSelf->_onSecondAuthCallback(code, resjsonStr);
        return;
    }];
end:
    if(result!=0){
        _blockSelf->_onSecondAuthCallback(result,nil);
        return;
    }
}

-(void)renewalKey:(NSMutableDictionary *)authKeyDict
         callback:(void (^)(int, NSString * _Nullable))onRenewalKeyCallback{
    int result = 0;
    __block SecondAuth *_blockSelf = self;
    [_blockSelf initiazeCallback:_blockSelf callback:onRenewalKeyCallback];
    
    NSMutableString *queryString = [[NSMutableString alloc]initWithString:PRMMODE];
    [queryString appendFormat:@"=%@",@"modeRenewalKey"];
    [queryString appendFormat:@"&%@",PRMSIGNATURE];
    [queryString appendFormat:@"=%@",[self urlencode:[authKeyDict objectForKey:@"signedData"]]];
    [queryString appendFormat:@"&%@",PRMPUB2];
    [queryString appendFormat:@"=%@",[self urlencode:[authKeyDict objectForKey:@"pub2"]]];
    [queryString appendFormat:@"&%@",PRMTOKEN];
    [queryString appendFormat:@"=%@",[self urlencode:[authKeyDict objectForKey:@"token"]]];
    [queryString appendFormat:@"&%@",PRMFINGERPRINT];
    [queryString appendFormat:@"=%@",[self urlencode:[authKeyDict objectForKey:@"fingerPrint"]]];
    NSLog(@"check renewalKey queryString %@",queryString);
    
    [_blockSelf sendServer:queryString callback:^(int code, NSString * _Nonnull resjsonStr) {
        _blockSelf->_onSecondAuthCallback(code, resjsonStr);
        return;
    }];
end:
    if(result!=0){
        _blockSelf->_onSecondAuthCallback(result,nil);
        return;
    }
}

-(void)deleteKey:(NSMutableDictionary *)deleteKeyDict
        callback:(void (^)(int code,
                           NSString *jsonStr))onDeleteKeyCallback{
    
    int result = 0;
    __block SecondAuth *_blockSelf = self;
    [_blockSelf initiazeCallback:_blockSelf callback:onDeleteKeyCallback];
    
    NSMutableString *queryString = [[NSMutableString alloc]initWithString:PRMMODE];
    [queryString appendFormat:@"=%@",@"modeDeleteKey"];
    [queryString appendFormat:@"&%@",PRMHRID];
    [queryString appendFormat:@"=%@",[self urlencode:[deleteKeyDict objectForKey:@"hrid"]]];
    
    [_blockSelf sendServer:queryString callback:^(int code, NSString * _Nonnull resjsonStr) {
        _blockSelf->_onSecondAuthCallback(code, resjsonStr);
        return;
    }];
end:
    if(result!=0){
        _blockSelf->_onSecondAuthCallback(result,nil);
        return;
    }
}

- (void)findRidInfo1:(NSMutableDictionary *)findRidInfo1Dict
            callback:(void (^)(int, NSString * _Nullable))onFindRidInfo1Callback{
    
    int result = 0;
    __block SecondAuth *_blockSelf = self;
    [_blockSelf initiazeCallback:_blockSelf callback:onFindRidInfo1Callback];
    
    NSMutableString *queryString = [[NSMutableString alloc]initWithString:PRMMODE];
    [queryString appendFormat:@"=%@",@"modeFindRidInfo1"];
    [queryString appendFormat:@"&%@",PRMUSERID];
    [queryString appendFormat:@"=%@",[self urlencode:[findRidInfo1Dict objectForKey:@"userID"]]];
    [queryString appendFormat:@"&%@",PRMFINGERPRINT];
    [queryString appendFormat:@"=%@",[self urlencode:[findRidInfo1Dict objectForKey:@"fingerPrint"]]];
    
    [_blockSelf sendServer:queryString callback:^(int code, NSString * _Nonnull resjsonStr) {
        _blockSelf->_onSecondAuthCallback(code, resjsonStr);
        return;
    }];
end:
    if(result!=0){
        _blockSelf->_onSecondAuthCallback(result,nil);
        return;
    }
}

-(void)findRidInfo2:(NSMutableDictionary *)findRidInfo2Dict
           callback:(void (^)(int code,
                              NSString *jsonStr))onFindRidInfo2Callback{
    
    int result = 0;
    __block SecondAuth *_blockSelf = self;
    [_blockSelf initiazeCallback:_blockSelf callback:onFindRidInfo2Callback];
    
    NSMutableString *queryString = [[NSMutableString alloc]initWithString:PRMMODE];
    [queryString appendFormat:@"=%@",@"modeFindRidInfo2"];
    [queryString appendFormat:@"&%@",PRMUSERID];
    [queryString appendFormat:@"=%@",[self urlencode:[findRidInfo2Dict objectForKey:@"userID"]]];
    
    [_blockSelf sendServer:queryString callback:^(int code, NSString * _Nonnull resjsonStr) {
        _blockSelf->_onSecondAuthCallback(code, resjsonStr);
        return;
    }];
end:
    if(result!=0){
        _blockSelf->_onSecondAuthCallback(result,nil);
        return;
    }
}
-(void)findRidInfo3:(NSMutableDictionary *)findRidInfo3Dict
           callback:(void (^)(int code,
                              NSString *jsonStr))onFindRidInfo3Callback{
    
    int result = 0;
    __block SecondAuth *_blockSelf = self;
    [_blockSelf initiazeCallback:_blockSelf callback:onFindRidInfo3Callback];
    
    NSMutableString *queryString = [[NSMutableString alloc]initWithString:PRMMODE];
    [queryString appendFormat:@"=%@",@"modeFindRidInfo1"];
    [queryString appendFormat:@"&%@",PRMUSERID];
    [queryString appendFormat:@"=%@",[self urlencode:[findRidInfo3Dict objectForKey:@"userID"]]];
    [queryString appendFormat:@"&%@",PRMFINGERPRINT];
    [queryString appendFormat:@"=%@",[self urlencode:[findRidInfo3Dict objectForKey:@"fingerPrint"]]];
    [queryString appendFormat:@"&%@",PRMAUTHTYPE];
    [queryString appendFormat:@"=%@",[self urlencode:[findRidInfo3Dict objectForKey:@"authType"]]];
    
    [_blockSelf sendServer:queryString callback:^(int code, NSString * _Nonnull resjsonStr) {
        _blockSelf->_onSecondAuthCallback(code, resjsonStr);
        return;
    }];
end:
    if(result!=0){
        _blockSelf->_onSecondAuthCallback(result,nil);
        return;
    }
}

-(void)initiazeCallback:(SecondAuth *)blockSelf
               callback:(void (^)(int resultCode, NSString *jsonStr))messagecallback{
    blockSelf->_onSecondAuthCallback = nil;
    blockSelf->_onSecondAuthCallback = messagecallback;
}


- (int)makejsonStrFromArray:(NSMutableArray *)jsonArray
                withJsonStr:(NSString *_Nonnull *_Nullable)str{
    
    int result = 0;
    NSError *error = nil;
    NSData *jsonData = nil;
    NSString *jsonStr = nil;
    
    jsonData = [NSJSONSerialization dataWithJSONObject:jsonArray
                                               options:NSJSONWritingPrettyPrinted error:&error];
    if(error!=nil){
        result = -1;
        goto end;
    }
    jsonStr = [[NSString alloc] initWithData:jsonData
                                                 encoding:NSUTF8StringEncoding];
end:
    *str = jsonStr;
    return result;
}

- (int)makejsonStr:(NSMutableDictionary *)jsonDict
       withJsonStr:(NSString **)str{
    int result = 0;
    NSError *error = nil;
    NSData *jsonData = nil;
    NSString *jsonStr = nil;
    
    if(jsonDict==nil){
        //invaild Input
        result = -10000;
        goto end;
    }
    
    jsonData=[NSJSONSerialization dataWithJSONObject:jsonDict
                                             options:NSJSONWritingPrettyPrinted
                                               error:&error];
    if(error!=nil){
        //jsonFailed...
        result = -10000;
        goto end;
    }
    jsonStr = [[NSString alloc]initWithData:jsonData encoding:NSUTF8StringEncoding];
    
end:
    *str = jsonStr;
    return result;
}


-(int)makeJsonObject:(NSString *)jsonStr withJsonData:(NSData **)jsonData{
    
    int result = 0;
    NSError *error = nil;
    NSData *_jsonData = nil;
    NSDictionary *jsonDict = [NSJSONSerialization JSONObjectWithData:[jsonStr dataUsingEncoding:NSUTF8StringEncoding] options:0 error:&error];
    if(error!=nil){
        //jsonFailed..
        result = -10000;
        goto end;
    }
    _jsonData=[NSJSONSerialization dataWithJSONObject:jsonDict
                                              options:0
                                                error:&error];
    if(error!=nil){
        //jsonFailed..
        result = -10000;
        goto end;
    }
end:
    *jsonData = _jsonData;
    return result;
}

- (NSString *)urlencode:(NSString *)str {
    NSMutableString *output = [NSMutableString string];
    const unsigned char *source = (const unsigned char *)[str UTF8String];
    unsigned int sourceLen = (unsigned int)strlen((const char *)source);
    for (int i = 0; i < sourceLen; ++i) {
        const unsigned char thisChar = source[i];
        if (thisChar == ' '){
            [output appendString:@"+"];
        } else if (thisChar == '.' || thisChar == '-' || thisChar == '_' || thisChar == '~' ||
                   (thisChar >= 'a' && thisChar <= 'z') ||
                   (thisChar >= 'A' && thisChar <= 'Z') ||
                   (thisChar >= '0' && thisChar <= '9')) {
            [output appendFormat:@"%c", thisChar];
        } else {
            [output appendFormat:@"%%%02X", thisChar];
        }
    }
    return output;
}


@end
