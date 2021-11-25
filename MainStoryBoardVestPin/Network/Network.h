//
//  Network.h
//  NativeSample
//
//  Created by yettie on 2021/01/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface Network : NSObject<NSURLSessionDelegate, NSURLSessionTaskDelegate>

-(NSMutableURLRequest *) makeRequest:(NSString *)url
                        withJsonBody:(NSData *)jsonBody;

-(void)sendServlet:(NSMutableURLRequest *)urlRequest
          callback:(void (^)(int code,
                             NSString  *jsonStr))networkCb;

@end

NS_ASSUME_NONNULL_END
