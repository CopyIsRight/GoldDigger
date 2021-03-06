//
//  SQLEntityMap.h
//  GoldDigger
//
//  Created by Felipe Lobo on 4/5/16.
//

#import "GDGEntityMap.h"

@protocol SQLSource;
@class SQLEntityQuery;
@class GDGHasOneRelation;
@class GDGHasManyRelation;
@class GDGBelongsToRelation;
@class GDGColumn;
@class GDGEntity;
@class GDGRelation;
@class SQLTableSource;
@class GDGHasManyThroughRelation;

@interface SQLEntityMap : GDGEntityMap

@property (strong, nonatomic) id <SQLSource> source;
@property (readonly, nonatomic) SQLTableSource *table;
@property (readonly, nonatomic) SQLEntityQuery *query;

- (void)hasOne:(NSString *)relationName config:(void (^)(GDGHasOneRelation *))tap;

- (void)hasMany:(NSString *)relationName config:(void (^)(GDGHasManyRelation *))tap;

- (void)hasMany:(NSString *)relationName through:(SQLTableSource *)table config:(void (^)(GDGHasManyThroughRelation *))tap;

- (void)belongsTo:(NSString *)relationName config:(void (^)(GDGBelongsToRelation *))tap;

- (NSString *)propertyFromColumnName:(NSString *)columnName;

- (NSString *)columnNameForProperty:(NSString *)propertyName;

- (GDGColumn *)columnForProperty:(NSString *)propertyName;

- (GDGRelation *)relationForProperty:(NSString *)relationName;

@end
