//
//  GDGCondition+EntityQuery.m
//  GoldDigger
//
//  Created by Pietro Caselani on 2/12/16.
//

#import "GDGCondition+EntityQuery.h"

#import <objc/runtime.h>
#import "GDGEntityQuery.h"
#import "GDGEntityManager.h"

@implementation GDGCondition (EntityQuery)

+ (instancetype)builderWithEntityQuery:(GDGEntityQuery *)entityQuery;
{
	GDGCondition *builder = [[self alloc] init];
	builder.query = entityQuery;

	return builder;
}

- (GDGEntityQuery *)query
{
	return objc_getAssociatedObject(self, _cmd);
}

- (void)setQuery:(GDGEntityQuery *)query
{
	objc_setAssociatedObject(self, @selector(query), query, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

- (GDGCondition *(^)(NSString *))prop
{
	GDGCondition *(^prop)(NSString *) = objc_getAssociatedObject(self, _cmd);
	if (prop == nil)
	{
		__weak typeof(self) weakSelf = self;

		prop = ^GDGCondition *(NSString *property) {
			return weakSelf.col([weakSelf.query.manager columnForProperty:property]);
		};

		objc_setAssociatedObject(self, _cmd, prop, OBJC_ASSOCIATION_COPY_NONATOMIC);
	}

	return prop;
}

@end