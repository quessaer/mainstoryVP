//
//  Network.m
//  NativeSample
//
//  Created by yettie on 2021/01/22.
//

#import "Network.h"

#define VPN_ALLOW_TRUST_SERVER_CERTIFICATE @"Always Allow VestPIN SSl Certificate"

@implementation Network

- (instancetype)init
{
    self = [super init];
    if (self) {
        return self;
    }
    return self;
}

-(NSMutableURLRequest *) makeRequest:(NSString *)url withJsonBody:(NSData *)jsonBody{
    
    NSURL *servletURL=[NSURL URLWithString:url];
    NSMutableURLRequest *request=[[NSMutableURLRequest alloc]init];
    
    NSDictionary *cookieProperties=[NSDictionary dictionaryWithObjectsAndKeys:
                                    servletURL.host,NSHTTPCookieDomain,
                                    servletURL.path,NSHTTPCookiePath,
                                    nil];
    
    NSHTTPCookie *cookie=[NSHTTPCookie cookieWithProperties:cookieProperties];
    NSArray* cookieArray=[NSArray arrayWithObjects:cookie,nil];
    NSDictionary *header=[NSHTTPCookie requestHeaderFieldsWithCookies:cookieArray];
    
    [request setHTTPMethod:@"POST"];
    //넣으면 에러...
    //[request addValue:@"application/json" forHTTPHeaderField:@"Content-Type"];
    [request addValue:@"*/*" forHTTPHeaderField:@"Accept"];
    [request setURL:servletURL];
    [request setHTTPBody:jsonBody];
    [request setAllHTTPHeaderFields:header];
    return request;
}

-(void)sendServlet:(NSMutableURLRequest *)urlRequest
          callback:(void (^)(int code,
                             NSString  *jsonStr))networkCb{
    
    NSURLSessionConfiguration *sessionConfig = [NSURLSessionConfiguration defaultSessionConfiguration];
    
    sessionConfig.requestCachePolicy = NSURLRequestReloadIgnoringLocalCacheData;
    
    NSURLSession *_session = [NSURLSession sessionWithConfiguration:sessionConfig delegate:self delegateQueue:[NSOperationQueue mainQueue]];
    
    NSURLSessionDataTask *_dataTask = [_session dataTaskWithRequest:urlRequest completionHandler:^(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error) {
        int result = 0;
        NSString *_jsonStr = nil;
        NSArray *cookies;
        NSHTTPURLResponse *httpResponse=(NSHTTPURLResponse *)response;
        NSLog(@"error %@",[error.userInfo objectForKey:@"_kCFStreamErrorCodeKey"]);
        NSString *errorCode = [error.userInfo objectForKey:@"_kCFStreamErrorCodeKey"];
        if(error!=nil){
            if([errorCode intValue] == [@"-9807" intValue]){
                //result = OSCAR_ERROR_SSL_UNTRUST_CERTIFICATE;
                goto end;
            }
            else{
                //result = OSCAR_ERROR_BAD_NETWORK;
                goto end;
            }
        }
        if(httpResponse.statusCode==200||httpResponse.statusCode==201){
            cookies = [NSHTTPCookie cookiesWithResponseHeaderFields:[httpResponse allHeaderFields] forURL:[httpResponse URL]];
            for (int i = 0; i<cookies.count; i++) {
                NSLog(@"check cookies %@",cookies[i]);
            }
            [[NSHTTPCookieStorage sharedHTTPCookieStorage] setCookies:cookies forURL:[httpResponse URL] mainDocumentURL:nil];
            if(data==nil){
                //result = OSCAR_ERROR_NO_DATA;
                goto end;
            }
            _jsonStr = [[NSString alloc]initWithData:data encoding:NSUTF8StringEncoding];
            NSLog(@"check jsonStr %@",[[NSString alloc]initWithData:data encoding:NSUTF8StringEncoding]);
        }
        else{
            NSLog(@"check Network Error %d",(int)httpResponse.statusCode);
            result = (int)httpResponse.statusCode;
            //network..Error...
        }
    end:
        networkCb(result,_jsonStr);
        return ;
    }];
    [_dataTask resume];
    [_session finishTasksAndInvalidate];
}

-(void)URLSession:(NSURLSession *)session didReceiveChallenge:(NSURLAuthenticationChallenge *)challenge completionHandler:(void (^)(NSURLSessionAuthChallengeDisposition, NSURLCredential * _Nullable))completionHandler {
    NSBundle* mainBundle = [NSBundle mainBundle];
    
    BOOL trust = [[mainBundle objectForInfoDictionaryKey:VPN_ALLOW_TRUST_SERVER_CERTIFICATE] boolValue];
    SecTrustRef serverTrust = challenge.protectionSpace.serverTrust;
    
    // Set SSL policies for domain name check
    NSMutableArray *policies = [NSMutableArray array];
    [policies addObject:(__bridge_transfer id)SecPolicyCreateSSL(true, (__bridge CFStringRef)challenge.protectionSpace.host)];
    SecTrustSetPolicies(serverTrust, (__bridge CFArrayRef)policies);
    // Evaluate server certificate
    SecTrustResultType result;
    SecTrustEvaluate(serverTrust, &result);
    NSURLCredential *credential;
    
    if([challenge.protectionSpace.authenticationMethod isEqualToString:NSURLAuthenticationMethodServerTrust]){
        //plist  에서 읽어옴
        if(trust){
            credential = [NSURLCredential credentialForTrust:challenge.protectionSpace.serverTrust];
        }
    }
    completionHandler(NSURLSessionAuthChallengeUseCredential, credential);
}
@end
