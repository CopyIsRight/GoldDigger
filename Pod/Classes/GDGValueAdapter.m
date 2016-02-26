//
//  GDGValueAdapter.m
//  Pods
//
//  Created by Pietro Caselani on 1/26/16.
//
//

#import "GDGValueAdapter.h"

@implementation GDGValueAdapter

+ (BOOL)allowsReverseTransformation
{
	return YES;
}

- (instancetype)initWithFromDatabaseHandler:(id (^)(id))fromDatabaseHandler toDatabaseHandler:(id (^)(id))toDatabaseHandler
{
	if (self = [super init])
	{
		_toDatabase = toDatabaseHandler;
		_fromDatabase = fromDatabaseHandler;
	}
	
	return self;
}

- (id)transformedValue:(id)value
{
	return _fromDatabase(value);
}

- (id)reverseTransformedValue:(id)value
{
	return _toDatabase(value);
}

@end
