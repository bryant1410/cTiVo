//
//  MTTiVoShow.h
//  cTiVo
//
//  Created by Scott Buchanan on 12/18/12.
//  Copyright (c) 2012 Scott Buchanan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "iTunes.h"
#import "MTTiVo.h"
#import "MTFormat.h"

@class MTProgramTableView;

@interface MTTiVoShow : NSObject <NSXMLParserDelegate> {
    NSFileHandle    *downloadFileHandle,
                    *decryptFileHandle,
                    *decryptLogFileHandle,
                    *decryptLogFileReadHandle,
                    *encodeFileHandle,
                    *encodeLogFileHandle,
                    *encodeLogFileReadHandle,
                    *bufferFileReadHandle,
                    *bufferFileWriteHandle,
                    *devNullFileHandle;
	NSString *downloadFilePath, *decryptFilePath, *decryptLogFilePath, *encodeFilePath, *encodeLogFilePath, *bufferFilePath;
    double dataDownloaded;
    NSTask *encoderTask, *decrypterTask;
	NSURLConnection *activeURLConnection, *detailURLConnection;
	NSPipe *pipe1, *pipe2;
	BOOL volatile writingData, downloadingURL, pipingData, isCanceled;
	off_t readPointer, writePointer;
	NSXMLParser *parser;
	NSMutableString *elementString;
	NSMutableArray *elementArray;
	NSArray *arrayHolder;
	BOOL    gotDetails;
	NSDictionary *parseTermMapping;
	double previousProcessProgress;
    NSDate *previousCheck;
}

@property (nonatomic, retain) NSString *urlString,
									*downloadDirectory,
									*mediaKey,
									*showTitle,
									*showDescription,
									*showTime,
									*showStatus,
									*episodeTitle,
									*showGenre,
									*episodeNumber,
									*isEpisode,
									*originalAirDate,
									*episodeGenre,
                                    *seriesTitle,
                                    *showDateString;

@property (nonatomic, retain) NSArray *vActor,
										*vExecProducer,
										*vProgramGenre,
										*vSeriesGenre,
										*vGuestStar,
										*vDirector;
@property (nonatomic, retain) NSDate *showDate;

@property (nonatomic, retain) NSNumber *downloadIndex;

@property (nonatomic, readonly) NSString *encodeFilePath;
@property (nonatomic, readonly) NSString *seasonEpisode; //attempts to build S02 E04 version
@property time_t showLength;  //length of show in seconds
@property (nonatomic, retain) NSURL *URL;
@property int  showID, season, episode, episodeYear, numRetriesRemaining, numStartupRetriesRemaining;
@property (retain) NSNumber *downloadStatus;
@property double processProgress; //Should be between 0 and 1
@property double fileSize;  //Size on TiVo;
@property (nonatomic, retain) MTFormat *encodeFormat;
@property (nonatomic, retain) MTTiVo *tiVo;
@property BOOL addToiTunesWhenEncoded, simultaneousEncode, isSimultaneousEncoding, isQueued,
                isSelected;//Used for refresh of table

@property (readonly) BOOL isInProgress;
@property (readonly) BOOL isMovie;
//@property (nonatomic, assign) MTProgramList *myTableView;

@property (readonly) NSDictionary * queueRecord;

-(BOOL) isSameAs:(NSDictionary *) queueEntry;
-(void) restoreDownloadData:(NSDictionary *) queueEntry;

-(void)cancel;
-(void)download;
-(void)decrypt;
-(void)encode;
-(void)getShowDetail;
//-(void)getShowDetailWithNotification;

+(NSDate *)dateForRFC3339DateTimeString:(NSString *)rfc3339DateTimeString;
+(NSString *)pathForExecutable:(NSString *)executable;



@end
