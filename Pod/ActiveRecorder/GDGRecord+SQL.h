//
//  GDGRecord+SQL.h
//  GoldDigger
//
//  Created by Felipe Lobo on 5/4/16.
//

#import "GDGEntity.h"

@class GDGMapping;
@class SQLEntityQuery;

@interface GDGRecord (SQL)

@property (strong, nonatomic) NSMutableArray *filledProperties;
@property (strong, nonatomic) NSMutableArray *changedProperties;

+ (GDGMapping *)db;

+ (instancetype)entityFromQuery:(GDGEntityQuery *)query;

+ (NSArray <__kindof GDGRecord *> *)entitiesFromQuery:(GDGEntityQuery *)query;

+ (void)autoFillProperties:(NSArray <NSString *> *)propertyNames;

+ (void)fill:(NSArray <GDGRecord *> *)entities withProperties:(NSArray *)properties;

- (void)fillProperties:(NSArray *)properties;

- (BOOL)save:(NSError **)error;

- (BOOL)delete:(NSError **)error;

@end