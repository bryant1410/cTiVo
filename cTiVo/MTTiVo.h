//
//  MTTiVo.h
//  cTiVo
//
//  Created by Scott Buchanan on 1/5/13.
//  Copyright (c) 2013 Scott Buchanan. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MTTiVoManager;

@interface MTTiVo : NSObject {
	BOOL volatile isConnecting;
	NSURLConnection *showURLConnection;
	NSMutableData *urlData;
}

@property (nonatomic, retain) NSNetService *tiVo;
@property (nonatomic, retain) NSMutableArray *shows;
@property (nonatomic, retain) NSDate *lastUpdated;
@property (nonatomic, retain) NSString *mediaKey;
@property (nonatomic, assign) NSOperationQueue *queue;
@property (nonatomic, retain) MTTiVoManager *tiVoManager;

+(MTTiVo *)tiVoWithTiVo:(NSNetService *)tiVo;

-(id) initWithTivo:(NSNetService *)tiVo;
-(void)updateShows;


@end
