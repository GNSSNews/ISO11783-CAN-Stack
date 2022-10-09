//================================================================================================
/// @file can_NAME.hpp
///
/// @brief A class that represents a control function's NAME
/// @author Adrian Del Grosso
///
/// @copyright 2022 Adrian Del Grosso
//================================================================================================

#ifndef CAN_NAME_HPP
#define CAN_NAME_HPP

#include <cstdint>
#include <tuple>

namespace isobus
{
	//================================================================================================
	/// @class NAME
	///
	/// @brief A class that represents an ISO11783 control function NAME from an address claim.
	//================================================================================================
	class NAME
	{
	public:
		/// @brief The encoded components that comprise a NAME
		enum class NAMEParameters
		{
			IdentityNumber, ///< Usually the serial number of the ECU, unique for all similar control functions
			ManufacturerCode, ///< The J1939/ISO11783 manufacturer code of the ECU with this NAME
			EcuInstance, ///< The ECU instance of the ECU with this NAME. Usually increments in NAME order with similar CFs
			FunctionInstance, ///< The function instance of the ECU. Similar to Virtual Terminal number.
			FunctionCode, ///< The function of the ECU, as defined by ISO11783
			DeviceClass, ///< Also known as the vehicle system from J1939, describes general ECU type
			DeviceClassInstance, ///< The instance number of this device class
			IndustryGroup, ///< The industry group associated with this ECU, such as "agricultural"
			ArbitraryAddressCapable ///< Defines if this ECU supports address arbitration
		};

		/// @brief See ISO11783-1 For complete descriptions of the ISO NAME function codes
		enum class Function : std::uint8_t
		{
			Engine = 0, ///< The typical mechanical power source of the machine
			AuxiliaryPowerUnit = 1, ///< Power source for operating systems without the use of the prime “drive” engine
			ElectricPropulsionControl = 2, ///< Control system which operates the drive mechanism when it is electrically powered
			Transmission = 3, ///< Mechanical system for altering the speed vs. torque output of the engine
			BatteryPackMonitor = 4, ///< Monitors the condition of a battery pack
			ShiftControl = 5, ///< Control Unit that determines and transmits onto the network the gear desired by the operator
			PowerTakeOffRearOrPrimary = 6, ///< System that controls the mechanical power derived from a prime engine and used to operate auxiliary items
			SteeringAxle = 7, ///< Adjusts attack angle of steering axle
			DrivingAxle = 8, ///< Adjusts attack angle of driving axle
			SystemControlBrakes = 9, ///< Controls service braking system electronically
			SteerAxleControlBrakes = 10, ///< Control for actuating the service brakes on a steered axle
			DriveAxleControlBrakes = 11, ///< Control for actuating the service brakes on a drive axle
			EnginerRetarder = 12, ///< Controller for the retarder capabilities of the engine
			DrivelineRetarder = 13, ///< Controller for the retarder capabilities of the driveline
			CruiseControl = 14, ///< Control system for maintaining the vehicle’s speed at a fixed operator selectable value
			FuelSystem = 15, ///< Controls fuel flow from the tank to the filter to the water removal/separator to the engine and then back to the tank
			SteeringControl = 16, ///< Controls steering in steer-by-wire
			SteerAxleSuspensionControl = 17, ///< Control system for the suspension of a steered axle
			DriveAxleSuspensionControl = 18, ///< Control system for the suspension of a driven axle
			InstrumentCluster = 19, ///< Gauge display for a vehicle, usually in the cab
			TripRecorder = 20, ///< System for accumulating data versus travel of the vehicle
			CabClimateControl = 21, ///< System for controlling the climate within the cab of the vehicle
			AerodynamicControl = 22, ///< Modifies drag by altering body panels
			VehicleNavigation = 23, ///< System associated with the vehicles physical location
			VehicleSecurity = 24, ///< System for comparing operator-provided data sequences against reference
			NetworkInterconnectUnit = 25, ///< ECU for connecting different network segments together
			BodyControl = 26, ///< Can handle suspension control for the body sections independent from the axle sections
			PowerTakeOffFrontOrSecondary = 27, ///< System that controls the mechanical power derived from a prime engine and used to operate auxiliary items
			OffVehicleGateway = 28, ///< ECU for connecting between vehicle network(s) and an off-vehicle system or network
			VirtualTerminal = 29, ///< General-purpose “intelligent” display with a specific message set defined in ISO 11783-6
			ManagementComputerOne = 30, ///< Manages vehicle systems, i.e. powertrain
			PropulsionBatteryCharger = 31, ///< Unit used to charge propulsion batteries in an electric vehicle
			HeadwayControl = 32, ///< Forward-looking collision avoidance, collision warning, speed controller, or speed control
			SystemMonitor = 33, ///< Generic system monitor
			HydraulicPumpControl = 34, ///< Pump controller that provides hydraulic power
			SystemControlSuspension = 35, ///< Controller responsible for coordinating the over-all suspension of a vehicle
			SystemControlPneumatic = 36, ///< Controller responsible for coordinating the pneumatics of a vehicle
			CabController = 37, ///< Controller located in/near vehicle cab used to perform functions that are grouped together for convenience
			TirePressureControl = 38, ///< Unit that provides control of centralized tire inflation
			IgnitionControl = 39, ///< Unit for altering the ignition of an engine
			SeatControl = 40, ///< System for controlling the seats (operator and passenger) within the cab
			OperatorControlsLighting = 41, ///< Controller for sending the operator lighting controls messages
			WaterPumpControl = 42, ///< Controller for a water pump mounted on the vehicle/machine
			TransmissionDisplay = 43, ///< Display designed specifically to display transmission information
			ExhaustEmissionControl = 44, ///< Emissions controller
			VehicleDynamicStabilityControl = 45, ///< Stability controller
			OilSystemMonitor = 46, ///< Monitors oil level, life, temperature
			InformationSystemControl = 47, ///< Information management for a vehicle’s application, such as cargo management
			RampControl = 48, ///< Loading unloading — chairlift, ramps, lifts or tailgates
			ClutchConverterControl = 49, ///< When transmission is distributed this handles torque converter lock-up or engine — transmission connection
			AuxiliaryHeater = 50, ///< Primary heat typically being taken from the engine coolant
			ForwardLookingCollisionWarningSystem = 51, ///< System which detects and warns of impending collision
			ChassisControl = 52, ///< Controls the chassis (not body or cab) components
			AlternatorElectricalChargingSystem = 53, ///< Vehicle’s primary on-board charging controller
			CommunicationsCellular = 54, ///< Radio communications unit designed to communicate via the cellular telephone system
			CommunicationsSatellite = 55, ///< Radio communications unit designed specifically to communicate via some satellite system
			CommunicationsRadio = 56, ///< Radio unit designed specifically to communicate via a terrestrial p2p system
			OperatorControlsSteeringColumn = 57, ///< Unit that gathers the operator inputs from switches/levers/etc and transmits associated messages
			FanDriveControl = 58, ///< Primary control system affecting the operation of the main cooling fan
			Starter = 59, ///< Mechanical system for initiating rotation in an engine
			CabDisplayCab = 60, ///< Used for a fairly elaborate in cab display, non VT and non instrument cluster
			FileServerOrPrinter = 61, ///< Printing or file storage unit on the network
			OnboardDiagnosticUnit = 62, ///< Tool that can be permanently mounted on the vehicle and which may not support all of the ISO 11783-12 messages
			EngineValveController = 63, ///< Control system used to manipulate the actuation of engine intake or exhaust
			EnduranceBraking = 64, ///< Sum of all units in a vehicle which enable the driver to brake with virtually no friction
			GasFlowMeasurement = 65, ///< Provides measurement of gas flow rates and associated parameters
			IOController = 66, ///< Reporting and/or control unit for external input and output channels
			ElectricalSystemController = 67, ///< Can include load centres, fuse boxes and power distribution boards
			AftertreatmentSystemGasMeasurement = 68, ///< Sensor for measuring gas properties before and after an aftertreatment system
			EngineEmissionAftertreatmentSystem = 69, ///< Engine Emission Aftertreatment System
			AuxiliaryRegenerationDevice = 70, ///< Auxiliary Regeneration Device used as part of an after treatment system
			TransferCaseControl = 71, ///< The device which controls the selection of the number of drive wheels (for example 2 or 4 wheel drive)
			CoolantValveController = 72, ///< Device used to control the flow of coolant (water, oil, air, etc…) for any thermal management system
			RolloverDetectionControl = 73, ///< Device designed for detection of vehicle rollover
			LubricationSystem = 74, ///< The Lubrication System pumps quantities of lubricant to each machine/vehicle joint that need to be lubricated
			SupplementalFan = 75, ///< This is an auxillary fan used for additional cooling. It is in addition to the primary cooling fan.
			TemperatureSensor = 76, ///< Device which measures temperature.
			FuelPropertiesSensor = 77, ///< Device which measures fuel properties
			FireSuppressionSystem = 78, ///< Fire Suppression System
			PowerSystemsManager = 79, ///< Controller application that manages the power output of one or more power systems. See also IG 5 Function 129 - Generator Set Controller
			ElectricPowertrain = 80, ///< Controller application in charge of controlling and coordinating the operation of an electric drive system
			HydraulicPowertrain = 81, ///< Controller application in charge of controlling and coordinating the operation of a hydraulic drive system
			FileServer = 82, ///< A file storage unit on the network - A permanent connection may exist and the unit is expected to store data (as in magnetic or eerom devices). See Function 61 for a combination File Server/Printer unit
			Printer = 83, ///< A printing unit on the network - A permanent connection may exist and the unit is expected to be able to print (paper type output). See Function 61 for a combination File Server/Printer unit
			StartAidDevice = 84, ///< Device that controls hardware and/or conveys information related to assisting an engine in starting, such as a glow plug, grid heater, etc.
			EngineInjectionControlModule = 85, ///< A device for direct or port injection of fuel for engine combustion and with which an engine controller may communicate
			EVCommunicationController = 86, ///< A controller or application that manages the connection to an external power source, i.e. the Electric Vehicle Supply Equipment
			DriverImpairmentDevice = 87, ///< Device which prevents the starting of a vehicle motor due to driver impairment. Example is an alcohol interlock device
			ElectricPowerConverter = 88, ///< An inverter or converter used to transform AC or DC power to or from an AC or DC source
			SupplyEquipmentCommunicationController = 89, ///< Typically part of an Electrical Vehicle Supply Equipment (EVSE) in an electric vehicle charging station
			VehicleAdapterCommunicationController = 90, ///< A controller inside of the adapter placed between an Electric Vehicle Supply Equipment (EVSE) vehicle connector and the vehicle inlet

			// Non-specific system industry group and vehicle system
			Reserved = 128, ///< Reserved
			OffBoardDiagnosticServiceTool = 129, ///< Off-board diagnostic-service tool
			OnBoardDiagnosticDataLogger = 130, ///< On-board data logger
			PCKeyboard = 131, ///< A user interface similar to a PC keyboard
			SafetyRestraintSystem = 132, ///< The safety restraint system can be for controlling activation of airbags, belt tensioners, roll over protection systems, etc
			Turbocharger = 133, ///< Turbocharger used on the engine
			GroundBasedSpeedSensor = 134, ///< Measures actual ground speed of a vehicle with a device such as radar or other such devices
			Keypad = 135, ///< An operator input device used to control machine functions or provide data
			HumiditySensor = 136, ///< Device which measures air humidity
			ThermalManagementSystemController = 137, ///< This device controls all devices that may be used in a thermal management system including Jacket Water Cooling, Charged Air Cooling, Transmission Cooling, Electronics Cooling, Aux Oil Cooling, etc
			BrakeStrokeAlert = 138, ///< The device that evaluates air brake stroke for normal stroke, over stroke, dragging brake, or a non-functioning brake actuator and is permanently mounted on the vehicle
			OnBoardAxleGroupScale = 139, ///< The device that determines axle group weights and is permanently mounted on the vehicle.
			OnBoardAxleGroupDisplay = 140, ///< The device that displays axle group weights and may be permanently mounted on the vehicle
			BatteryCharger = 141, ///< A device used to charge batteries in a vehicle from an off-board source of electrical energy.
			TurbochargerCompressorBypass = 142, ///< Device used to control the flow across the Compressor Bypass
			TurbochargerWastegate = 143, ///< Device used to control the position of the Wastegate to adjust the exhaust flow
			Throttle = 144, ///< Device used to control the air/fuel mixture into the cylinders for combustion
			InertialSensor = 145, ///< Detects a change in geographic position, a change in velocity, and/or a change in orientation. This may include but is not limited to an accelerometer, gyroscopes, etc
			FuelActuator = 146, ///< Device used to control the flow of fuel (or fuel rack) on a engine
			EngineExhaustGasRecirculation = 147, ///< Device that controls the engine exhaust gas recirculation system
			EngineExhaustBackpressure = 148, ///< Device that controls the engine exhaust backpressure
			OnBoardBinWeightingScale = 149, ///< Device that determines bin weights and is permanently mounted on the vehicle
			OnBoardBinWeighingScalDisplay = 150, ///< Device that displays bin weights and may be permanently mounted on the vehicle
			EngineCylinderPressureMonitoringSystem = 151, ///< System designed to monitor engine cylinder pressures and provide combustion information
			ObjectDetection = 152, ///< System for detection of undesireable objects in the product flow
			ObjectDetectionDisplay = 153, ///< Display designed specifically for displaying and managing object detection information
			ObjectDetectionSensor = 154, ///< Detects the presence of objects within a region.
			PersonnelDetectionDevice = 155, /// < Device for the detection of personnel in proximity to a vehicle.

			// Non-specific system industry group 1
			Tachograph = 128,
			DoorController = 129,
			ArticulationTurntableControl = 130,
			BodyToVehicleInterfaceControl = 131,
			SlopeSensor = 132,
			RetarderDisplay = 134,
			DifferentialLockController = 135,
			LowVoltageDisconnect = 136,
			RoadwayInformation = 137,
			AutomatedDriving = 138,

			// Tractor industry group 1
			ForwardRoadImageProcessing = 128,
			FifthWheelSmartSystem = 129,
			CatalystFluidSensor = 130,
			AdaptiveFrontLightingSystem = 131,
			IdleControlSystem = 132,
			UserInterfaceSystem = 133,

			// Non-specific system industry group 2
			NonVirtualTerminalDisplay = 128,

			MaxFunctionCode = 255 ///< Max allocated function code
		};

		/// @brief A structure that tracks the pair of a NAME parameter and associated value
		typedef std::pair<const NAMEParameters, const std::uint32_t> NameParameterFilter;

		/// @brief Constructor for a NAME
		/// @param[in] rawNAMEData The raw 64 bit NAME of an ECU
		explicit NAME(std::uint64_t rawNAMEData);

		/// @brief Returns if the ECU is capable of address arbitration
		/// @returns true if the ECU can arbitrate addresses
		bool get_arbitrary_address_capable() const;

		/// @brief Sets the data in the NAME that corresponds to the arbitration capability of the ECU
		/// @param[in] value True if the ECU supports arbitration, false if not
		void set_arbitrary_address_capable(bool value);

		/// @brief Returns the industry group encoded in the NAME
		/// @returns The industry group encoded in the NAME
		std::uint8_t get_industry_group() const;

		/// @brief Sets the industry group encoded in the NAME
		/// @param[in] value The industry group to encode in the NAME
		void set_industry_group(std::uint8_t value);

		/// @brief Returns the device class (vehicle system) encoded in the NAME
		/// @returns The device class (vehicle system) encoded in the NAME
		std::uint8_t get_device_class_instance() const;

		/// @brief Sets the device class instance (vehicle system) to be encoded in the NAME
		/// @param[in] value The device class instance (vehicle system) to be encoded in the NAME
		void set_device_class_instance(std::uint8_t value);

		/// @brief Returns the device class (vehicle system) encoded in the NAME
		/// @returns The device class (vehicle system) encoded in the NAME
		std::uint8_t get_device_class() const;

		/// @brief Sets the device class (vehicle system) to be encoded in the NAME
		/// @param[in] value The device class (vehicle system) to be encoded in the NAME
		void set_device_class(std::uint8_t value);

		/// @brief Gets the function code encoded in the NAME
		/// @returns The function code encoded in the NAME
		std::uint8_t get_function_code() const;

		/// @brief Sets the function code encoded in the NAME
		/// @param[in] value The function code to be encoded in the NAME
		void set_function_code(std::uint8_t value);

		/// @brief Gets the function instance encoded in the NAME
		/// @returns The function instance encoded in the NAME
		std::uint8_t get_function_instance() const;

		/// @brief Sets the function instance encoded in the NAME
		/// @param[in] value The function instance to be encoded in the NAME
		void set_function_instance(std::uint8_t value);

		/// @brief Gets the ecu instance encoded in the NAME
		/// @returns The ecu instance encoded in the NAME
		std::uint8_t get_ecu_instance() const;

		/// @brief Sets the ecu instance encoded in the NAME
		/// @param[in] value The ecu instance to be encoded in the NAME
		void set_ecu_instance(std::uint8_t value);

		/// @brief Gets the manufacturer code encoded in the NAME
		/// @returns The manufacturer code encoded in the NAME
		std::uint16_t get_manufacturer_code() const;

		/// @brief Sets the manufacturer code encoded in the NAME
		/// @param[in] value The manufacturer code to be encoded in the NAME
		void set_manufacturer_code(std::uint16_t value);

		/// @brief Gets the identity number encoded in the NAME
		/// @returns The identity number encoded in the NAME
		std::uint32_t get_identity_number() const;

		/// @brief Sets the identity number encoded in the NAME
		/// @param[in] value The identity number to be encoded in the NAME
		void set_identity_number(std::uint32_t value);

		/// @brief Gets the raw 64 bit NAME
		/// @returns The raw 64 bit NAME
		std::uint64_t get_full_name() const;

		/// @brief Sets the raw, encoded 64 bit NAME
		/// @param[in] value The raw, encoded 64 bit NAME
		void set_full_name(std::uint64_t value);

	private:
		std::uint64_t rawName; ///< A raw, 64 bit NAME encoded with all NAMEParameters
	};
} // namespace isobus

#endif // CAN_NAME_HPP
