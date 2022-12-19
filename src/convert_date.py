    from libtad import BusinessDateService
    from libtad.datatypes.places import Coordinates, LocationId
    from libtad.datatypes.time import TADDateTime
    from libtad.datatypes.business import BusinessDaysFilterType, BusinessDaysOperatorType
    
    coordinates = Coordinates(59.743, 10.204)
    place = LocationId(coordinates)
    date = TADDateTime(2020, 11, 26)
    days = 14
    service = BusinessDateService("accessKey", "secretKey")
    service.filter = [BusinessDaysFilterType.Weekend, BusinessDaysFilterType.Holidays]
    
    # Count forward from start date
    service.operator = BusinessDaysOperatorType.Add
    # Count backwards from start date
    service.operator = BusinessDaysOperatorType.Subtract


result = service.get_business_date_for_place(place, date, days)
